LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;


ENTITY sintesis_cerrojo IS
  PORT (
    rst			: IN  std_logic;
    clk			: IN  std_logic;
    boton		: IN  std_logic;
    clave 		: IN  std_logic_vector (7 DOWNTO 0);
    bloqueado 	: OUT std_logic_vector (15 DOWNTO 0);
    display		: OUT std_logic_vector (6 DOWNTO 0);
    s_display	: OUT std_logic_vector (3 DOWNTO 0)
  );
END sintesis_cerrojo;

ARCHITECTURE cerrojoArch OF sintesis_cerrojo IS

    COMPONENT cerrojo IS
      PORT (
        rst			  : IN  std_logic;
        clk			  : IN  std_logic;
        boton		  : IN  std_logic;
        clave 		: IN  std_logic_vector (7 DOWNTO 0);
        bloqueado : OUT std_logic;
        intentos    : OUT std_logic_vector (3 DOWNTO 0)
      );
    END COMPONENT;

  COMPONENT debouncer
    PORT (
      rst: IN std_logic;
      clk: IN std_logic;
      x: IN std_logic;
      xDeb: OUT std_logic;
      xDebFallingEdge: OUT std_logic;
      xDebRisingEdge: OUT std_logic
    );
  END COMPONENT;
   
  COMPONENT conv_7seg is
    Port ( x : in  STD_LOGIC_VECTOR (3 downto 0);
           display : out  STD_LOGIC_VECTOR (6 downto 0));
  end COMPONENT;
  
  SIGNAL st : std_logic_vector (3 DOWNTO 0);
  SIGNAL salidaDebouncer, bloqueado_aux, srst : std_logic;

BEGIN
srst <= not rst;
	debouncerInstance: debouncer PORT MAP (srst, clk, boton, open, open, salidaDebouncer);
  cerrojoInstance : cerrojo PORT MAP (rst, clk, salidaDebouncer, clave, bloqueado_aux, st );
	conv_7segInstance: conv_7seg PORT MAP (st, display);
  bloqueado <= (others => bloqueado_aux );
	s_display <= "1110";
  
END cerrojoArch;
