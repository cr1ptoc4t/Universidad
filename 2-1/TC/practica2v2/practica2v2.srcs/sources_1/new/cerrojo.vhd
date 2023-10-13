
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

ENTITY cerrojo IS
    PORT (
    rst : IN std_logic;
    clk : IN std_logic;
    boton : IN std_logic;
    clave : IN std_logic_vector (7 DOWNTO 0);
    bloqueado : OUT std_logic;
    intentos : OUT std_logic_vector (3 DOWNTO 0)
    );
END cerrojo;

architecture Behavioral of cerrojo is
    type ESTADOS is (S1, S2, S3, S4, S5);
	signal ESTADO, SIG_ESTADO: ESTADOS;
	--signal eq: std_logic ;
	signal senal_buena: std_logic_vector (7 downto 0);
	
begin

--intentos <="0011";

SYNC: process (clk, rst, boton)
begin

    if rst='1' then
		ESTADO<= S1;
	elsif rising_edge(clk) and boton='1' then
			ESTADO<= SIG_ESTADO;
	end if;
	
end process SYNC;


COMB: process(ESTADO, boton)
begin    
   case ESTADO is
        
    when S1 => 
        intentos<="0011";
        bloqueado<='1';
        
        if boton = '1' then
            senal_buena <= clave; --lee contraseña nueva
            SIG_ESTADO <=S2;
        end if;
        
    when S2 =>
     bloqueado<='0';
     intentos<="0011";
     
     
    if senal_buena = clave then  -- if eq='1'then
        SIG_ESTADO <=S1;
    else 
        SIG_ESTADO <=S3;
    end if;
     
    when S3 =>
        bloqueado<='0';
        intentos <= "0010";
        
   
            if senal_buena = clave then
                SIG_ESTADO <=S1;
            else 
                SIG_ESTADO <=S4;
            end if;
     
    when S4 =>
        intentos <="0001";
        bloqueado<='0';
        
        --if boton = '1' then
            if senal_buena = clave then
                SIG_ESTADO <=S1;
            else 
                SIG_ESTADO <=S5;
             end if;
       -- end if;
     
     when S5 =>
         bloqueado<='0';
         intentos <="0000";
         
         if clave = "10101010" then
            SIG_ESTADO <= S1;
         else 
            SIG_ESTADO<=S5;
         end if;
         
         
    
    end case;
    
end process COMB;

end Behavioral;
