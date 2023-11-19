
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity data_path is
generic(
    n : natural;
    m : natural
);
port(
    clk : in std_logic; 
    reset : in std_logic
);
end data_path;

architecture ARCH of data_path is
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
-- declaration of components and remaining intermediate signals...
begin
-- code of the datapath...

end ARCH;