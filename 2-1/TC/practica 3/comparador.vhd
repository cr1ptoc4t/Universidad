library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.ALL;

entity comparador is
    generic(
        num_bits: natural := 4
    );
    port(
        x, ci: in std_logic_vector(num_bits - 1 downto 0);
        ci1: out std_logic_vector(num_bits - 1 downto 0);
        z: out std_logic_vector(num_bits - 1 downto 0)
    );
end comparador;

architecture rtl of comparador is
    --signals
    signal x_signal: signed(x);
    signal ci_signal: signed(ci);
    begin
    COMB: process(x_signal, ci_signal)
    begin
        if (TO_INTEGER(signed(xi)) >= TO_INTEGER(signed(ci))) then
            ci1 <= xi;
        else
            ci1 <= ci;
        end if;
    end process;
end rtl;


--if(TO_INTEGER(signed(xi)) >= TO_INTEGER(signed(ci)))
---
---COMB: process(x_signal, ci_signal)
---begin
---    if(x_signal < ci_signal) then
---        ci1 <= std_logic_vector(ci_signal);
---    else 
---        ci1 <= std_logic_vector(x_signal);
---    end if; 
---
