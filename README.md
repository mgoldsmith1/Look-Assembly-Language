# Look-Assembly
This is a Regex-like assembly language that I wrote in C++. This project includes a compiler and an assembler. More documentation to be added.

_________________________________
The following is a sample program:
     
    ;this is a comment 

          det      100   ; begins at memory address 100
    hi    look     x     ; navigates to the contents of x from memory and observes the symbol 'hi' from the symbol table
          pack     x     ; loads x into a temporary memory allocator
    hey   acc      y     ; stores the location of 'hey' into the memory address of y and is loaded into an accumulator
          write    x
          bp       hi
    ^     ?        x     ; Prints the first value of x. Not yet implemented.  
    $     ?        x     ; Prints the last value of x. Not yet implemented.  
          ?        x     ; Prints the value of x
          halt
   
    x     declare   5    ; declares the address space limit for x
    y     declare   88
    r     declare   444
    a     declare   200
          end            ; terminates program
 
