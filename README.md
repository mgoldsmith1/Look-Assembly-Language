# Look-Assembly
A Regex-like assembly language that I wrote in C++. This project includes a compiler and an assembler. 

The purpose is to create a low-level language that provides inferential logic to avoid traversals in an undirected graph. 

_________________________________
The following is a sample program:
```bash     
    ;this is a comment 

          det      100   ; The assembler begins reading instructions starting at memory address 100
    hi    look     x     ; Locates the contents of x from memory containing the address of the symbol 'hi'. 
                         ; Returns the symbol location. 
                         
          pack     x     ; Loads the contents of x into a temporary memory allocator
          
    hey   acc      y     ; Stores the location of 'hey' into the symbol table during compilation the 
                         ; memory address of y is appended to the location of 'hey' on the symbol table and
                         ; is then loaded into an accumulator during run time.
                         
          write    x
          bp       hi
          halt
   
    x     declare   5    
    y     declare   88
    r     declare   444
    a     declare   200
          end            ; terminates program
```
Not yet Implemented:
```bash
    ^     ?        x     ; Prints the first value of x.  
    $     ?        x     ; Prints the last value of x. 
          ?        x     ; Prints the value of x
          
    sift  A?       x     ; the sift iterator will loop through forall (A?) the contents found in x
    *.=1  sieve    !#    ; the sieve filter will find all that are not numbers (!#) 
                         ; the (*.=?) look ahead is an iteration limiter 
                         ; in this case (*.=1) we stop the sift iterator while filtering nums at postion 1
                         
          pack     y, x  ; pack will load the contents of x into y 
          ?        y     ; prints all that are not nums from y discovered from x
```
For example:
```bash
          det      100   ; The assembler begins reading instructions starting at memory address 100
    hi    look     x     ; Locates the contents of x from memory containing the address of the symbol 'hi'. 
                         ; Returns the symbol location. 
                         
          pack     x     ; Loads the contents of x into a temporary memory allocator
          
    ^     ?        x     ; Prints the first value of x.  
    $     ?        x     ; Prints the last value of x. 
          ?        x     ; Prints the value of x
          
    sift  A?       x     ; the sift iterator will loop through forall (A?) the contents found in x
    *.=1  sieve    !#    ; the sieve filter will find all that are not numbers (!#) 
                         ; the (*.=?) look ahead is an iteration limiter 
                         ; in this case (*.=1) we stop the sift iterator while filtering nums at postion 1
                         
          pack     y, x  ; pack will load the contents of x into y 
          ?        y     ; prints all that are not nums from y discovered from x
          halt
          
    x     declare   5    
          end
```          
          
          
   
 
