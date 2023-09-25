--Librerias necesarias
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_textio.all;
use std.textio.all;
 
 
ENTITY tb_registro IS
END tb_registro;
 
ARCHITECTURE behavior OF tb_registro IS 
 
-- Declaraci?n del componente que vamos a simular
 
    COMPONENT registro
    PORT(
        rst : IN  std_logic;
        clk : IN  std_logic;
		load: IN std_logic;
        E : IN  std_logic_vector(3 downto 0);
        S : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;

--Entradas
    signal rst : std_logic;
    signal clk : std_logic;
    signal E : std_logic_vector(3 downto 0);
	 signal load: std_logic;
		
--Salidas
    signal S : std_logic_vector(3 downto 0);
   
--Se define el periodo de reloj 
    constant clk_period : time := 50 ns;
 
BEGIN
 
-- Instanciacion de la unidad a simular 

   uut: registro PORT MAP (
         rst => rst,
         clk => clk,
		 load => load,
         E => E,
         S => S
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
      load <= '0';
      E<="0000";
      wait for 45 ns;
-- Dejamos de resetear	
      rst<='0';
      load <= '0';
      E<="0000";
      wait for 50 ns;	
-- Cargamos el valor "1101" en el registro
      rst<='0';
      load <= '1';
      E<="1101";
      wait for 50 ns;	
-- Mantenemos el valor durante 100 ns
      rst<='0';
      load <= '0';
      E<="0000"; 
      wait for 100 ns;	
-- Cargamos el valor "0011" en el registro 
      rst<='0';
      load <= '1';
      E<="0011"; 
      wait for 50 ns;	
-- Mantenemos el valor para siempre
      rst<='0';
      load <= '0';
      E<="0000"; 
      wait;	
end process;

END;