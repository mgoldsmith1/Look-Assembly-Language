# Look-Assembly
This is an assembly language that I wrote in C++. This project includes a compiler and an assembler. More documentation to be added.

_________________________________
The following is a sample program:
     
    ;this is a comment 

          det      100   ; begins at memory address 100
    hi    look     x     ; observes x as the representation of the string 'hi' 
          pack     x     ; loads x into a temporary memory allocator
    hey   acc      y     ; stores the location of 'hey' into the memory address of y
          write    x
          bp       hi
          halt
   
    x     declare   5    ; declares the address space limit for x
    y     declare   88
    r     declare   444
    a     declare   200
          end            ; terminates program
 
