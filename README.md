# Look-Assembly
A Regex-like assembly language that I wrote in C++. This project includes a compiler and an assembler. More documentation to be added.

_________________________________
The following is a sample program:
     
    ;this is a comment 

          det      100   ; The assembler begins reading instructions starting at memory address 100
    hi    look     x     ; Locates the contents of x from memory containing the address of the symbol 'hi'. Returns the symbol location. 
          pack     x     ; Loads the contents of x into a temporary memory allocator
    hey   acc      y     ; Stores the location of 'hey' into the symbol table, during compilation the memory address of y is appended to 
                         ; the location of hey on the symbol table and is loaded into the accumulator during run time.
          write    x
          bp       hi
    ^     ?        x     ; Prints the first value of x. Not yet implemented.  
    $     ?        x     ; Prints the last value of x. Not yet implemented.  
          ?        x     ; Prints the value of x
          halt
   
    x     declare   5    
    y     declare   88
    r     declare   444
    a     declare   200
          end            ; terminates program
 
