LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;


ENTITY sintesis_div IS
generic (n : natural := 8;
	         m: natural := 4);
  PORT (
    clk			: IN  std_logic;
    rst			: IN  std_logic;
     dividendo : in std_logic_vector (7 downto 0);
     divisor: in std_logic_vector (3 downto 0);
     inicio		: IN  std_logic;
     fin 	: OUT std_logic;

     display		: OUT std_logic_vector (6 DOWNTO 0);
     s_display	: OUT std_logic_vector (3 DOWNTO 0);
     cociente: out std_logic_vector (7 downto 0)
  );
END sintesis_div;



ARCHITECTURE divArch OF sintesis_div IS
component divisor_ent is
generic (n : natural := 8;
	         m: natural := 4);

	port (clk, rst: in std_logic;
	dividendo: in std_logic_vector (n -1 downto 0);
	divisor: in std_logic_vector (m-1 downto 0);
	inicio: in std_logic;
	fin: out std_logic;
	cociente: out std_logic_vector (n-1 downto 0));
end component;

component displays is
    Port ( 
        rst : in STD_LOGIC;
        clk : in STD_LOGIC;       
        digito_0 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_1 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_2 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_3 : in  STD_LOGIC_VECTOR (3 downto 0);
        display : out  STD_LOGIC_VECTOR (6 downto 0);
        display_enable : out  STD_LOGIC_VECTOR (3 downto 0)
     );
end component;
   
  signal cociente_signal: std_logic_vector (n-1 downto 0);
BEGIN

	divInstance : divisor_ent PORT MAP (clk, rst,dividendo, divisor,   inicio, fin, cociente_signal );
cociente <= cociente_signal;
	conv_7segInstance: displays PORT MAP (rst, clk, cociente_signal(3 downto 0), cociente_signal(7 downto 4), "0000", "0000", display, s_display );
  
END divArch;
