-- Librerías necesarias
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
entity divisor_ent is
  generic (
    n : natural;
    m : natural
  );
  port (
    clk : in std_logic;
    rst : in std_logic;
    dividendo : in std_logic_vector(n-1 downto 0);
    divisor : in std_logic_vector(m-1 downto 0);
    inicio : in std_logic
    --cociente : out std_logic_vector(n-1 downto 0);
    --less_or_equals : out std_logic;
    --MSB_dividend : out std_logic
  );
end divisor_ent;

architecture ARCH of divisor_ent is
  signal control : std_logic_vector(8 downto 0);
  signal fin : std_logic;
  signal MSB_dividend : std_logic;
  signal less_or_equals : std_logic;
  signal cociente : std_logic_vector(n-1 downto 0);

  component data_path
    generic (
      n : natural;
      m : natural
    );
    port (
      clk : in std_logic;
      rst : in std_logic;
      dividendo : in std_logic_vector(n-1 downto 0);
      divisor : in std_logic_vector(m-1 downto 0);
      control : in std_logic_vector(8 downto 0);
      cociente : out std_logic_vector(n-1 downto 0);
      less_or_equals : out std_logic;
      MSB_dividend : out std_logic
    );
  end component;

  component controller
    port (
      clk : in std_logic;
      rst : in std_logic;
      inicio : in std_logic;
      less_or_equals : in std_logic;
      MSB_dividend : in std_logic;
      control : out std_logic_vector(8 downto 0);
      fin : out std_logic
    );
  end component;

begin
  my_datapath : data_path
    generic map (n, m)
    port map (
      clk => clk,
      rst => rst,
      dividendo => dividendo,
      divisor => divisor,
      control => control,
      cociente => cociente,
      less_or_equals => less_or_equals,
      MSB_dividend => MSB_dividend
    );

  my_controller : controller
    port map (
      clk => clk,
      rst => rst,
      inicio => inicio,
      less_or_equals => less_or_equals,
      MSB_dividend => MSB_dividend,
      control => control,
      fin => fin
    );

end ARCH;
