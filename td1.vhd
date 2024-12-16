library ieee;
use ieee.std_logic_1164.all;

entity td1 is
    port (
        A : in std_logic;
        B : in std_logic;
        Cin : in std_logic;

        Cout : out std_logic;
        S : out std_logic
    );
end entity td1;

architecture blbl of td1 is
    signal S1 : std_logic; 
    signal S2 : std_logic; 
    signal S3 : std_logic; 
begin
    S1 <= A xor B;
    S2 <= Cin and S1;
    S3 <= A and B;
    S =< S1 xor Cin;
    Cout <= S2 or S3;
end architecture blbl;