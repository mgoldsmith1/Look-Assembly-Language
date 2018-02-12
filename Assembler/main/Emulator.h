//
//		Emulator class - supports the emulation of Look Assembly programs
//
#ifndef _EMULATOR_H      // UNIX way of preventing multiple inclusions.
#define _EMULATOR_H
#include "Assembler.h"
class emulator {

public:
       const static int MEMSZ = 10000;	// The size of the memory of the Look assembler.
       emulator() {

		memset( m_memory, 0, MEMSZ * sizeof(int) ); //***Initalized everything to 0. Part of old C style library
       }
       // Records instructions and data into Look memory.
        bool insertMemory( int a_location, int a_contents ){ //***This is a bool to see if it was done sucessfully or not. 	
	    m_memory[a_location] = a_contents;	
		return true;		  
	}
        // Runs the Look program recorded in memory.
	bool runProgram(int a_loc){
		for (int i = a_loc; i < a_loc && a_loc < MEMSZ; ++i) { 
			cout << m_memory[i] << endl;
		}
		return true;
	}

private:
		// The memory of the Look assembly code.
		int m_memory[MEMSZ];
};
#endif

