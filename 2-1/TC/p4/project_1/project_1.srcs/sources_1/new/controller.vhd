----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.11.2023 22:48:19
-- Design Name: 
-- Module Name: controller - Behavioral
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

entity controller is
port(clk, reset, inicio: in std_logic;
less_or_equals: in std_logic;
MSB_dividend: in std_logic;
control: out std_logic_vector(8 downto 0);
fin: out std_logic);
end controller;

architecture Behavioral of controller is
    type STATES is (S0,S1,S2,S3,S4,S5,S6,S7); 
    
    signal STATE, NEXT_STATE: STATES;
    signal control_aux: std_logic_vector(8 downto 0);
    alias load_dividend : std_logic is control_aux(0);
    alias load_divisor : std_logic is control_aux(1);
    alias shift_right_divisor: std_logic is control_aux(2);
    alias load_quotient : std_logic is control_aux(3);
    alias shift_left_quotient : std_logic is control_aux(4);
    alias load_k : std_logic is control_aux(5);
    alias count_k : std_logic is control_aux(6);
    alias mux_dividend : std_logic is control_aux(7);
    alias operation : std_logic is control_aux(8);
begin
--Processes SYNC and COMB of the finite state machine (as in Lab 2)

   
    PROCESS(clk, reset)
    BEGIN
        IF reset = '1' THEN
            STATE <= S0;
        ELSIF rising_edge(clk) THEN
            STATE <= NEXT_STATE;
        END IF;
    END PROCESS;


    PROCESS (STATE, inicio)
    BEGIN
        -- Lógica de transición de estados
        CASE STATE IS
            WHEN S0 =>
                IF inicio = '1' THEN
                    NEXT_STATE <= S1; -- Cambia al siguiente estado cuando inicio es 0
                ELSE
                    NEXT_STATE <= S0; -- Permanece en el mismo estado si inicio no es 0
                END IF;
            WHEN S1 =>
             NEXT_STATE <= S2;
            WHEN S2=>
              NEXT_STATE <= S3;
            WHEN S3 =>
            --si no -
            NEXT_STATE <=S4;
            -- SI SI
           -- NEXT_STATE <=S5;
            
            WHEN S4=>
            NEXT_STATE <= S6;
            WHEN S5=>
             NEXT_STATE <= S6;
            WHEN S6=>
             NEXT_STATE <= S7;
            WHEN S7=>
              -- AQUI NO SE CUANDO VUELVE AL S2 Y CUANDO VUELVE AL S0
        END CASE;
   

    -- Otras acciones según la lógica de tu aplicación
    if STATE = S0 and inicio = '0' then
    
        -- Acciones específicas para el estado S0 cuando inicio es 0
        -- Agrega aquí tus asignaciones y lógica específica
    end if;
    END PROCESS;
end Behavioral;
