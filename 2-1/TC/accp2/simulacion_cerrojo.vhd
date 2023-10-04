--Librerias necesarias
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY simulacion_cerrojo IS
END simulacion_cerrojo;
 
ARCHITECTURE behavior OF simulacion_cerrojo IS 
 
-- Declaraci?n del componente que vamos a simular
   
    COMPONENT cerrojo IS
      PORT (
        rst			  : IN  std_logic;
        clk			  : IN  std_logic;
        boton		  : IN  std_logic;
        clave 		: IN  std_logic_vector (7 DOWNTO 0);
        bloqueado : OUT std_logic;
        intentos    : OUT std_logic_vector (3 DOWNTO 0)
      );
    END COMPONENT;

--Entradas
    signal rst : std_logic;
    signal clk : std_logic;
    signal boton, bloqueado: std_logic; 
		
--Salidas
    signal clave : std_logic_vector(7 downto 0);
    signal intentos : std_logic_vector(3 downto 0);
   
--Se define el periodo de reloj 
    constant clk_period : time := 50 ns;
 
BEGIN
 
-- Instanciacion de la unidad a simular 

   uut: cerrojo PORT MAP (
         rst => rst,
         clk => clk,
         boton => boton,
		     clave => clave,
         bloqueado => bloqueado,
         intentos => intentos
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
      boton <= '0';
      clave <= "00000000";
      wait for 45 ns;
-- Dejamos de resetear	
      rst<='0';
      boton <= '0';
      clave <= "00000000";
      wait for 150 ns;	
-- Cargamos clave
      rst<='0';
      boton <= '1';
      clave <= "00110010";
      wait for 50 ns;	
-- Espera
      rst<='0';
      boton <= '0';
      clave <= "00110010";
      wait for 500 ns;
-- Fallamos clave
      rst<='0';
      boton <= '1';
      clave <= "00100010";
      wait for 50 ns;	
-- Espera
      rst<='0';
      boton <= '0';
      clave <= "00100010";
      wait for 500 ns;
-- Fallamos clave
      rst<='0';
      boton <= '1';
      clave <= "10100010";
      wait for 50 ns;	
-- Espera
      rst<='0';
      boton <= '0';
      clave <= "10100010";
      wait for 500 ns;
-- Acertamos clave
      rst<='0';
      boton <= '1';
      clave <= "00110010";
      wait for 50 ns;	
-- Espera
      rst<='0';
      boton <= '0';
      clave <= "00110010";
      wait for 500 ns;     
-- Cargamos clave
      rst<='0';
      boton <= '1';
      clave <= "11111111";
      wait for 50 ns;	
-- Espera
      rst<='0';
      boton <= '0';
      clave <= "11111111";
      wait for 500 ns;
-- Fallamos clave
      rst<='0';
      boton <= '1';
      clave <= "00000000";
      wait for 50 ns;	
-- Espera
      rst<='0';
      boton <= '0';
      clave <= "00000000";
      wait for 500 ns;
-- Fallamos clave
      rst<='0';
      boton <= '1';
      clave <= "10000000";
      wait for 50 ns;	
-- Espera
      rst<='0';
      boton <= '0';
      clave <= "10000000";
      wait for 500 ns;
-- Fallamos clave
      rst<='0';
      boton <= '1';
      clave <= "11000000";
      wait for 50 ns;	
-- Espera indefinida
      rst<='0';
      boton <= '0';
      clave <= "11000000";
      wait;
end process;

END;

