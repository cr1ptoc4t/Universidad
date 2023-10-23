----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.10.2023 19:10:53
-- Design Name: 
-- Module Name: red_arbol_comparadores - Behavioral
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

function Log2( input:integer ) return integer is
    variable temp,log: integer;
begin
    temp:=input;
    log:=0;
    while (temp >1) loop
        temp:=temp/2;
        log:=log+1;
    end loop;
    return log;
end function log2;

type C_type is array (Log2(num_entradas) downto 0, num_entradas-1 downto 0) of std_logic_vector(num_bits-1 downto 0);
signal C : C_type;

begin
gen_entradas: for i in 0 to num_entradas-1 generate
C(0,i) <= X(--- downto ---);
end generate gen_entradas;

end Behavioral;



architecture Behavioral of red_arbol_comparadores is

begin


end Behavioral;
