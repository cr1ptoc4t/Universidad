----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 20.12.2023 15:19:22
-- Design Name: 
-- Module Name: estados - Behavioral
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

entity estados is
    Port (clk, rst, x: in std_logic;
    Z: out std_logic
    );
end estados;

architecture Behavioral of estados is
    type ESTADOS is (S0, S1, S2, S3);
    signal ESTADO, SIG_ESTADO: ESTADOS;
    
    
begin
    
    SYNC: process(clk, rst)
        begin
            if rising_edge(clk) then
                if rst='1' then
                    ESTADO<=S0;
                else
                    ESTADO<=SIG_ESTADO;
                end if;
            end if;
    end process SYNC;

    COMB: process (ESTADO, x)
    begin
        SIG_ESTADO <= ESTADO;
        z<='0';
        case ESTADO is
            when S0=>
                if x='0' then
                    SIG_ESTADO<= S1;
                end if;
            when S1=>
               if x='0' then
                SIG_ESTADO<=S2;
               else
                SIG_ESTADO<=S0;
               end if;
            when S2=>
                if x='1' then
                    SIG_ESTADO<=S3;
                end if;
            when S3=>
                if x='0' then
                    SIG_ESTADO<=S1;
                else
                    SIG_ESTADO<=S0;
                    z<='1';
                end if;
        end case;
    end process COMB;

end Behavioral;
