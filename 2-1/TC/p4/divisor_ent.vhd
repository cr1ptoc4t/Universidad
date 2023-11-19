--Librerias necesarias
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY simulacion IS
END simulacion;
 
ARCHITECTURE behavior OF simulacion IS 
 
-- Declaraci?n del componente que vamos a simular
   
	component divisor_ent
  generic (n : natural := 8;
	         m: natural := 4);
	  Port (
		clk : in std_logic;
		 rst : in std_logic;
 		dividendo: in std_logic_vector(n-1 downto 0);
		divisor: in std_logic_vector(m-1 downto 0);
		inicio        : IN  std_logic;
		fin           : OUT std_logic;
		cociente : out std_logic_vector(n-1 downto 0)
	  );
	end component;

--Entradas
    signal rst : std_logic;
    signal clk : std_logic;
	signal inicio : std_logic;
	signal dividendo, cociente: std_logic_vector(7 downto 0);
	signal divisor: std_logic_vector(3 downto 0);
--Salidas
	signal fin : std_logic;
   
--Se deinicioe el periodo de reloj 
    constant clk_period : time := 50 ns;
 
BEGIN
 
-- Instanciacion de la unidad a simular 

   uut: divisor_ent PORT MAP (
          clk => clk,
		  rst => rst,
		  dividendo => dividendo,
		  divisor=> divisor,
          inicio => inicio,
	      fin => fin,	 
          cociente => cociente
        );

-- Definicion del process de reloj
reloj_process :process
   begin
	clk <= '0';
	wait for clk_period/2;
	clk <= '1';
	wait for clk_period/2;
end process;
 

--Proceso de estimulos
stim_proc: process
   begin		
-- Se mantiene el rst activado durante 45 ns.
      rst<='1';
      inicio <= '0';
      dividendo <= "00000000";
      divisor <= "0000";
      wait for 45 ns;
-- Dejamos de resetear	
      rst<='0';
      inicio <= '0';
      dividendo <= "00000000";
      divisor <= "0000";
      wait for 150 ns;	
-- Cargamos datos (48/8)
      rst<='0';
      inicio <= '1';
      dividendo <= "00110000";
      divisor <= "1000";
      wait for 100 ns;	
-- Espera  
      inicio <= '0';
      dividendo <= "00000000";
      divisor <= "0000";
      wait for 3000ns;
-- Cargamos datos (240/20)
      rst<='0';
      inicio <= '1';
      dividendo <= "11110000";
      divisor <= "1100";
      wait for 100 ns;	
      -- Espera  
      inicio <= '0';
      dividendo <= "00000000";
      divisor <= "0000";
      wait for 3000ns;
-- Cargamos datos (32/7)
      rst<='0';
      inicio <= '1';
      dividendo <= "00100000";
      divisor <= "0111";
      wait for 100 ns;	
-- Espera  indefinida
      inicio <= '0';
      dividendo <= "00000000";
      divisor <= "0000";
      wait;

end process;

END;

