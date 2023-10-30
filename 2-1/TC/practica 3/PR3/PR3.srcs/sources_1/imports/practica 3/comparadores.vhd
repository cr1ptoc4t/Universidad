---comparadores.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.ALL;


--ENTITY, define externamente al circuito
entity red_iterativa_comparadores is
    generic(        --Lista de parámetros genéricos
        num_bits: natural := 4;
        num_entradas: natural := 4
    );
    port(           --Lista de puertos de entrada y salida
        X : in std_logic_vector(num_entradas*num_bits-1 downto 0);
        S : out std_logic_vector(num_bits-1 downto 0)
    );
end red_iterativa_comparadores;


architecture struct of red_iterativa_comparadores is --ARCHITECTURA, Define internamente al circuito
    --components
    component comparador
    port(
        x: in std_logic_vector(num_bits - 1 downto 0);
        c: in std_logic_vector(num_bits - 1 downto 0);
        c1: out std_logic_vector(num_bits - 1 downto 0);
        z: out std_logic_vector(num_bits - 1 downto 0)
    );
    end component;
    --signals
    signal C: std_logic_vector ((num_entradas+1)*num_bits -1 downto 0); --para que carajo crea una señal c, a ya entendi
	constant N : natural := 10;

    begin
        --generate
        gen_comparadores: for i in 0 to num_entradas generate
            comp_i : comparador
                port map(
                  X((i+1)*num_bits - 1 downto i*num_bits),
                  C((i+1)*num_bits - 1 downto i * num_bits),
                  C((i+2)*num_bits - 1 downto i*num_bits)
                );
                
                S <= C(num_entradas*num_bits-1 downto num_entradas *num_bits-4);
        
        end generate gen_comparadores;
    

end struct;
--x(0) = x(num_bits - 1 downto 0);
--x(i) = x((i+1)num_bits - 1 downto i * num_bits);