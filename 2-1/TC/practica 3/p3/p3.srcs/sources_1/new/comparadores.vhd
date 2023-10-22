----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.10.2023 17:56:43
-- Design Name: 
-- Module Name: comparadores - Behavioral
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
use IEEE.NUMERIC_STD.SIGNED;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;



entity comparadores is
--  Port ( );
end comparadores;

entity red_arbol_comparadores is
generic (
    num_bits : natural := 4;
    num_entradas : natural := 4
);
port(
    X : in std_logic_vector (num_entradas*num_bits-1 downto 0);
    S : out std_logic_vector (num_bits-1 downto 0)
);
end red_arbol_comparadores;


architecture Behavioral of comparadores is

begin


end Behavioral;
