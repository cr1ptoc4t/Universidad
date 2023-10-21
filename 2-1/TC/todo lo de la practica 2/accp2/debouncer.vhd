LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY debouncer IS
  PORT (
    rst: IN std_logic;
    clk: IN std_logic;
    x: IN std_logic;
    xDeb: OUT std_logic;
    xDebFallingEdge: OUT std_logic;
    xDebRisingEdge: OUT std_logic
  );
END debouncer;

ARCHITECTURE debouncerArch of debouncer is

  SIGNAL xSync: std_logic;
  SIGNAL startTimer, timerEnd: std_logic;
  
BEGIN

  synchronizer:
  PROCESS (rst, clk)
    VARIABLE aux1: std_logic;
  BEGIN
    IF (rst='0') THEN
      aux1 := '1';
      xSync <= '1';
    ELSIF (clk'EVENT AND clk='1') THEN
      xSync <= aux1;
      aux1 := x;           
    END IF;
  END PROCESS synchronizer;

  timer:
  -- espera 50 ms para un reloj a 12.5 MHz
  PROCESS (rst, clk)
    CONSTANT timeOut: std_logic_vector (19 DOWNTO 0) := "10011000100101101000";
    VARIABLE count: std_logic_vector (19 DOWNTO 0);
  BEGIN
    IF (count=timeOut) THEN
      timerEnd <= '1';
    ELSE 
      timerEnd <= '0';
    END IF;
    IF (rst='0') THEN
      count := timeOut;
    ELSIF (clk'EVENT AND clk='1') THEN
      IF (startTimer='1') THEN
        count := (OTHERS=>'0');
      ELSIF (timerEnd='0') THEN
        count := count + 1;
      END IF;
    END IF;
  END PROCESS timer;
    
  controller:
  PROCESS (xSync, rst, clk)
    TYPE states IS (waitingPression, pressionDebouncing, waitingDepression, depressionDebouncing); 
    VARIABLE state: states;
  BEGIN 
    xDeb <= '1';
    xDebFallingEdge <= '0';
    xDebRisingEdge <= '0';
    startTimer <= '0';
    CASE state IS
      WHEN waitingPression =>
        IF (xSync='0') THEN
          xDebFallingEdge <= '1';
          startTimer <= '1';
        END IF;
      WHEN pressionDebouncing =>
        xDeb <= '0';
      WHEN waitingDepression =>
        xDeb <= '0';
        IF (xSync='1') THEN
          xDebRisingEdge <= '1';
          startTimer <= '1';
        END IF;
      WHEN depressionDebouncing =>
        NULL;
      END CASE;
    IF (rst='0') THEN
      state := waitingPression;
    ELSIF (clk'EVENT AND clk='1') THEN
      CASE state IS
        WHEN waitingPression =>
          IF (xSync='0') THEN
            state := pressionDebouncing;
          END IF;
        WHEN pressionDebouncing =>
          IF (timerEnd='1') THEN
            state := waitingDepression;
          END IF;
        WHEN waitingDepression =>
          IF (xSync='1') THEN
            state := depressionDebouncing;
          END IF;
        WHEN depressionDebouncing =>
          IF (timerEnd='1') THEN
            state := waitingPression;
          END IF;
      END CASE;
    END IF;
  END PROCESS controller;  

END debouncerArch;
