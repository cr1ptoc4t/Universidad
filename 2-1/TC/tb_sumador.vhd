LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_TEXTIO.ALL;
USE STD.TEXTIO.ALL;

--entidad
 
ENTITY tb_sumador IS
END tb_sumador;
 
--arquitectura

ARCHITECTURE behavioural OF tb_sumador IS 
 
-- Declaraci?n del componente que vamos a simular

    COMPONENT sumador
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         C : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    
--Entradas
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');

--Salidas
   signal C : std_logic_vector(3 downto 0);
  
BEGIN
 
-- Instanciacion de la unidad a simular 
   uut: sumador PORT MAP (
          A => A,
          B => B,
          C => C
        );

-- Proceso de estimulos
stim_proc: process
   begin		
		A<="0000";
		B<="0000";
      wait for 100 ns;
		A<="0101";
		B<="0100";
      wait for 100 ns;
		A<="0000";
		B<="0111";
      wait for 100 ns;
		A<="0011";
		B<="1000";
      wait for 100 ns;
		A<="1011";
		B<="1111";
      wait for 100 ns;
		A<="1001";
		B<="0110";
      wait;
end process;

END behavioural;