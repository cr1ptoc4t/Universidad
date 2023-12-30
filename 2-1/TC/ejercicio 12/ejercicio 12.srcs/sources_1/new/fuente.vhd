----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 20.12.2023 15:45:57
-- Design Name: 
-- Module Name: fuente - Behavioral
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
use IEEE.numeric_std.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity fuente is
    Port (
    clk: in std_logic;
    rst: in std_logic;
    desplazamiento: in std_logic_vector(2 downto 0);
    num: in std_logic_vector(6 downto 0);
    z: out std_logic_vector(7 downto 0)
    );
end fuente;

architecture Behavioral of fuente is
    signal salidaYEntrada: STD_LOGIC_VECTOR(14 downto 0);
    signal salidaInterna: std_logic_vector (7 downto 0);
begin
    salidaYEntrada <= salidaInterna & num;
    
    SYNC: process(clk, rst)
    begin
        if rising_edge(clk) then
            if rst='1' then
                salidaInterna<= (others=>'0');
            else
                salidaInterna <= salidaYEntrada(14- to_integer(unsigned(desplazamiento)) downto 7-to_integer(unsigned(desplazamiento)));
            end if;
        end if;
    end process SYNC;
    
    z<= salidaInterna;



end Behavioral;
