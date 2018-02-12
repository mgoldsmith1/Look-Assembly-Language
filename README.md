# The-Look-Assembly-Language
This is an assembly language that I wrote in C++. This project includes a compiler and an assembler. More documentation to be added.

This is roughly how this program should be interperated:
________________________________________________________

Press Enter to continue...

Translation of Program:

Location    Contents    Original Statement
					                                      ;this is a test
0                                det     100
100          070100     hi       look     x     ;comment immediately after statement
101          050100              pack     x
102          060101     hey      acc      y     ;This will accumulate the contents of y which is hey
103          080100              write    x
104          120100              bp       hi
105          130000              halt
						                                    ; test
100          000005     x        declare  5
101                     y        declare  88
206          000555     b        declare  444
207          000100     a        declare  200
				 end
________________________________________________________
Press Enter to continue...

Results from emulating program:

? 10
10
? 144
144
?-7
-7

End of emulation
