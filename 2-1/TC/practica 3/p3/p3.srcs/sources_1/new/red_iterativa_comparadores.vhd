----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.10.2023 17:59:51
-- Design Name: 
-- Module Name: red_iterativa_comparadores - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;



entity red_iterativa_comparadores is
	generic (
		num_bits: natural:=4;
		num_entradas: natural :=4
	);
	port(
		X: in std_logic_vector (num_entradas *num_bits-1 downto 0);
		S: out std_logic_vector (num_bits downto 0)
	);
end red_iterativa_comparadores;


architecture Behavioral of red_iterativa_comparadores is
    component celda
    Port(
         X : in std_logic;      
         C_in : in std_logic;   
         C_out : out std_logic;
         Z : out std_logic
    );

    end component ;
     
	signal C: std_logic_vector ((num_entradas+1)*num_bits -1 downto 0);
	constant N : natural := 10;

begin

    gen1: for i in 0 to N generate
        u: celda port map(
            X(i),
            C(i), 
            C(i+1)--, 
            --Z(i)
        );
	end generate gen1;


end Behavioral;

