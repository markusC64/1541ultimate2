library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library work;
use work.io_bus_pkg.all;
use work.mem_bus_pkg.all;

entity mm_drive is
generic (
    g_big_endian    : boolean;
    g_audio_tag     : std_logic_vector(7 downto 0) := X"01";
    g_floppy_tag    : std_logic_vector(7 downto 0) := X"02";
    g_disk_tag      : std_logic_vector(7 downto 0) := X"03";
    g_cpu_tag       : std_logic_vector(7 downto 0) := X"04";
    g_audio         : boolean := true;
    g_audio_base    : unsigned(27 downto 0) := X"0030000";
    g_ram_base      : unsigned(27 downto 0) := X"0060000" );
port (
    clock           : in  std_logic;
    reset           : in  std_logic;
    drive_stop      : in  std_logic := '0';
    
    -- timing
    tick_16MHz      : in  std_logic;
    tick_4MHz       : in  std_logic;
    tick_1kHz       : in  std_logic;

    -- slave port on io bus
    io_req          : in  t_io_req;
    io_resp         : out t_io_resp;
    io_irq          : out std_logic;

    -- master port on memory bus
    mem_req         : out t_mem_req_32;
    mem_resp        : in  t_mem_resp_32;
    
    -- serial bus pins
    atn_o           : out std_logic; -- open drain
    atn_i           : in  std_logic;
    clk_o           : out std_logic; -- open drain
    clk_i           : in  std_logic;              
    data_o          : out std_logic; -- open drain
    data_i          : in  std_logic;              
    fast_clk_o      : out std_logic; -- open drain
    fast_clk_i      : in  std_logic;

    iec_reset_n     : in  std_logic := '1';
    c64_reset_n     : in  std_logic := '1';
    
    -- parallel bus pins
    via1_port_a_o   : out std_logic_vector(7 downto 0);
    via1_port_a_i   : in  std_logic_vector(7 downto 0) := X"55";
    via1_port_a_t   : out std_logic_vector(7 downto 0);
    via1_ca2_o      : out std_logic;
    via1_ca2_i      : in  std_logic := '1';
    via1_ca2_t      : out std_logic;
    via1_cb1_o      : out std_logic;
    via1_cb1_i      : in  std_logic := '1';
    via1_cb1_t      : out std_logic;

    -- Debug port
    debug_data      : out std_logic_vector(31 downto 0);
    debug_valid     : out std_logic;

    -- LED
    act_led_n       : out std_logic;
    motor_led_n     : out std_logic;
    dirty_led_n     : out std_logic;

    -- audio out
    audio_sample    : out signed(12 downto 0) );

end entity;

architecture structural of mm_drive is
    signal tick_16M_i       : std_logic;
    signal cia_rising       : std_logic;
    signal cpu_clock_en     : std_logic;
    signal iec_reset_o      : std_logic;
    
    signal do_track_out     : std_logic;
    signal do_track_in      : std_logic;
    signal do_head_bang     : std_logic;
    signal do_snd_insert    : std_logic;
    signal do_snd_remove    : std_logic;
    signal en_hum           : std_logic;
    signal en_slip          : std_logic;

    signal use_c64_reset    : std_logic;
    signal floppy_inserted  : std_logic := '0';
    signal force_ready      : std_logic;
    signal bank_is_ram      : std_logic_vector(7 downto 1);
    signal two_MHz          : std_logic;
    signal power            : std_logic;
    signal motor_sound_on   : std_logic;
    signal motor_on         : std_logic;
    signal mode             : std_logic;
    signal side             : std_logic;
    signal stepper_en       : std_logic;
    signal step             : std_logic_vector(1 downto 0) := "00";
    signal rate_ctrl        : std_logic_vector(1 downto 0);
    signal byte_ready       : std_logic;
    signal sync             : std_logic;
    signal track            : unsigned(6 downto 0);
	signal drive_address	: std_logic_vector(1 downto 0) := "00";
	signal write_prot_n	    : std_logic := '1';
    signal disk_change_n    : std_logic := '1';
    signal rdy_n            : std_logic := '1';
	signal track_0          : std_logic := '0';
    signal drv_reset        : std_logic := '1';
    signal disk_rdata       : std_logic_vector(7 downto 0);
    signal disk_wdata       : std_logic_vector(7 downto 0);
    signal drive_stop_i     : std_logic;
    signal stop_on_freeze   : std_logic;
    signal drive_type       : natural range 0 to 2;
         
    signal io_req_regs      : t_io_req;
    signal io_resp_regs     : t_io_resp;
    signal io_req_param     : t_io_req;
    signal io_resp_param    : t_io_resp;
    signal io_req_dirty     : t_io_req;
    signal io_resp_dirty    : t_io_resp;
    signal io_req_wd        : t_io_req;
    signal io_resp_wd       : t_io_resp;

    signal mem_req_cpu      : t_mem_req;
    signal mem_resp_cpu     : t_mem_resp;
    signal mem_req_flop     : t_mem_req;
    signal mem_resp_flop    : t_mem_resp;
    signal mem_req_snd      : t_mem_req := c_mem_req_init;
    signal mem_resp_snd     : t_mem_resp;
    signal mem_req_disk     : t_mem_req;
    signal mem_resp_disk    : t_mem_resp;
    signal mem_req_8        : t_mem_req := c_mem_req_init;
    signal mem_resp_8       : t_mem_resp;
    signal mem_busy         : std_logic;
    
    signal count            : unsigned(7 downto 0) := X"00";
	signal led_intensity	: unsigned(1 downto 0);
begin        
    i_splitter: entity work.io_bus_splitter
    generic map (
        g_range_lo => 11,
        g_range_hi => 12,
        g_ports    => 4
    )
    port map(
        clock      => clock,
        req        => io_req,
        resp       => io_resp,
        reqs(0)    => io_req_regs,
        reqs(1)    => io_req_dirty,
        reqs(2)    => io_req_param,
        reqs(3)    => io_req_wd,
        resps(0)   => io_resp_regs,
        resps(1)   => io_resp_dirty,
        resps(2)   => io_resp_param,
        resps(3)   => io_resp_wd
    );

    i_timing: entity work.c1541_timing
    port map (
        clock        => clock,
        reset        => reset,
        
        tick_4MHz    => tick_4MHz,
        two_MHz_mode => two_MHz,
        mem_busy     => mem_busy,

        use_c64_reset=> use_c64_reset,
        c64_reset_n  => c64_reset_n,
        iec_reset_n  => iec_reset_n,
        iec_reset_o  => iec_reset_o,
    
        power        => power,
        drive_stop   => drive_stop_i,
    
        cia_rising   => cia_rising,
        cpu_clock_en => cpu_clock_en ); -- 1 MHz or 2 MHz

    drive_stop_i <= drive_stop and stop_on_freeze;
    tick_16M_i   <= tick_16MHz and not drive_stop_i;

    i_cpu: entity work.mm_drive_cpu
    generic map (
        g_cpu_tag      => g_cpu_tag,
        g_disk_tag     => g_disk_tag,
        g_ram_base     => g_ram_base )
    port map (
        clock       => clock,
        falling     => cpu_clock_en,
        rising      => cia_rising,
        reset       => drv_reset,
        tick_1kHz   => tick_1kHz,
        tick_4MHz   => tick_4MHz,

        -- Drive type!!
        drive_type  => drive_type,
        
        -- serial bus pins
        atn_o       => atn_o, -- open drain
        atn_i       => atn_i,
        clk_o       => clk_o, -- open drain
        clk_i       => clk_i,    
        data_o      => data_o, -- open drain
        data_i      => data_i,
        fast_clk_o  => fast_clk_o, -- open drain
        fast_clk_i  => fast_clk_i,

        -- parallel bus pins
        par_data_o   => via1_port_a_o,
        par_data_i   => via1_port_a_i,
        par_data_t   => via1_port_a_t,
        par_hsout_o  => via1_ca2_o,
        par_hsout_i  => via1_ca2_i,
        par_hsout_t  => via1_ca2_t,
        par_hsin_o   => via1_cb1_o,
        par_hsin_i   => via1_cb1_i,
        par_hsin_t   => via1_cb1_t,

        -- trace data
        debug_data  => debug_data,
        debug_valid => debug_valid,
        
		-- configuration
        extra_ram       => bank_is_ram(7), -- FIXME: signal name

		-- memory interface
        mem_req_cpu     => mem_req_cpu,
        mem_resp_cpu    => mem_resp_cpu,
        mem_req_disk    => mem_req_disk,
        mem_resp_disk   => mem_resp_disk,
        mem_busy        => mem_busy,

        -- i/o interface to wd177x
        io_req          => io_req_wd,
        io_resp         => io_resp_wd,
        io_irq          => io_irq,

        -- drive pins
        power           => power,
        drive_address   => drive_address,
        write_prot_n    => write_prot_n,
        motor_sound_on  => motor_sound_on,
        motor_on        => motor_on,
        stepper_en      => stepper_en,
        mode            => mode,
        step            => step,
        side            => side,
        rate_ctrl       => rate_ctrl,
        byte_ready      => byte_ready,
        sync            => sync,
        two_MHz         => two_MHz,
        rdy_n           => rdy_n,
        disk_change_n   => disk_change_n,
        track_0         => track_0,
        track           => track,

        drv_rdata       => disk_rdata,
        drv_wdata       => disk_wdata,
    
        -- other
        power_led       => open, -- FIXME
        act_led         => act_led_n );

    -- This may look odd; but 'motor on' is always 0 for the 1581, to shut off the GCR module
    -- MotorSound, however, is enabled for 1581, and has the same function as motor_on.
    rdy_n       <= not (motor_sound_on and floppy_inserted) and not force_ready; -- should have a delay
    
    i_flop: entity work.floppy
    generic map (
        g_big_endian   => g_big_endian,
        g_tag          => g_floppy_tag )
    port map (
        clock           => clock,
        reset           => drv_reset,
        tick_16MHz      => tick_16M_i,
        
        -- signals from MOS 6522 VIA
        stepper_en      => stepper_en,
        motor_on        => motor_on,
        mode            => mode,
        write_prot_n    => write_prot_n,
        step            => step,
        side            => side,
        rate_ctrl       => rate_ctrl,
        byte_ready      => byte_ready,
        sync            => sync,
        
        read_data       => disk_rdata,
        write_data      => disk_wdata,
        
        track           => track,
        track_is_0      => track_0,
    ---
        io_req_param    => io_req_param,
        io_resp_param   => io_resp_param,
        io_req_dirty    => io_req_dirty,
        io_resp_dirty   => io_resp_dirty,
    ---
        floppy_inserted => floppy_inserted,
        do_track_out    => do_track_out,
        do_track_in     => do_track_in,
        do_head_bang    => do_head_bang,
        dirty_led_n     => dirty_led_n,
    ---
        mem_req         => mem_req_flop,
        mem_resp        => mem_resp_flop );

    en_hum  <= motor_sound_on and not floppy_inserted;
    en_slip <= motor_sound_on and floppy_inserted;

    r_snd: if g_audio generate
        i_snd: entity work.floppy_sound
        generic map (
            g_tag          => g_audio_tag,
            sound_base     => g_audio_base(27 downto 16),
            motor_hum_addr => X"0000",
            flop_slip_addr => X"1200",
            track_in_addr  => X"2400",
            track_out_addr => X"2C00",
            head_bang_addr => X"3480",
            insert_addr    => X"3D00",
            remove_addr    => X"7D00",
            motor_len      => 4410,
            track_in_len   => X"0800",  -- ~100 ms
            track_out_len  => X"0880",  -- ~100 ms
            head_bang_len  => X"0880",  -- ~100 ms
            insert_len     => X"3F80",  -- ~740 ms
            remove_len     => X"3800" ) -- ~650 ms
        
        port map (
            clock           => clock,
            reset           => drv_reset,
            
            tick_4MHz       => tick_4MHz,

            do_trk_out      => do_track_out,
            do_trk_in       => do_track_in,
            do_head_bang    => do_head_bang,
            do_insert       => do_snd_insert,
            do_remove       => do_snd_remove,
            en_hum          => en_hum,
            en_slip         => en_slip,
            
        	-- memory interface
        	mem_req		    => mem_req_snd,
        	mem_resp        => mem_resp_snd,
        
            -- audio
            sample_out      => audio_sample );
    end generate;

    i_regs: entity work.drive_registers
    generic map (
        g_multi_mode    => true )
    port map (
        clock           => clock,
        reset           => reset,
        tick_1kHz       => tick_1kHz,

        io_req          => io_req_regs,
        io_resp         => io_resp_regs,
        
        iec_reset_o     => iec_reset_o,
        use_c64_reset   => use_c64_reset,
        power           => power,
        drv_reset       => drv_reset,
        drive_address   => drive_address,
        floppy_inserted => floppy_inserted,
        disk_change_n   => disk_change_n,
        force_ready     => force_ready,
        write_prot_n    => write_prot_n,
        bank_is_ram     => bank_is_ram,
        stop_on_freeze  => stop_on_freeze,
        drive_type      => drive_type,
        do_snd_insert   => do_snd_insert,
        do_snd_remove   => do_snd_remove,

        track           => track,
        side            => side,
        mode            => mode,
        motor_on        => motor_sound_on );
            
    -- memory arbitration
    i_arb: entity work.mem_bus_arbiter_pri
    generic map (
        g_ports      => 4,
        g_registered => false )
    port map (
        clock       => clock,
        reset       => reset,
        
        reqs(0)     => mem_req_flop,
        reqs(1)     => mem_req_cpu,
        reqs(2)     => mem_req_snd,
        reqs(3)     => mem_req_disk,
        
        resps(0)    => mem_resp_flop,
        resps(1)    => mem_resp_cpu,
        resps(2)    => mem_resp_snd,
        resps(3)    => mem_resp_disk,
        
        req         => mem_req_8,
        resp        => mem_resp_8 );        

    i_conv32: entity work.mem_to_mem32(route_through)
    generic map (
        g_big_endian => g_big_endian )
    port map(
        clock       => clock,
        reset       => reset,
        mem_req_8   => mem_req_8,
        mem_resp_8  => mem_resp_8,
        mem_req_32  => mem_req,
        mem_resp_32 => mem_resp );

    process(clock)
    	variable led_int : unsigned(7 downto 0);
    begin
        if rising_edge(clock) then
            count <= count + 1;
			if count=X"00" then
				motor_led_n <= '0'; -- on
			end if;
			led_int := led_intensity & led_intensity & led_intensity & led_intensity;
			if count=led_int then
				motor_led_n <= '1'; -- off
			end if;
        end if;
    end process;

	led_intensity <= "00" when power='0' else
					 "01" when floppy_inserted='0' else
					 "10" when motor_on='0' else
					 "11";

end architecture;
