//
//		Assembler class.  This is a container for all the components
//		that make up the assembler.
//
#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "SymTab.h"
#include "Instruction.h"
#include "FileAccess.h"
#include "Emulator.h"
#include <iomanip> 

class Assembler {

public:
        Assembler( int argc, char *argv[] );
       ~Assembler( );

       // Pass I - establish the locations of the symbols
       void PassI( );

       // Pass II - generate a translation
       void PassII( ); //TO DO

        //Feeds and appends a series of machine instructions
       void Feed(int opCode, int loc, int symbolLoc);

       // Display the symbols in the symbol table.
       void DisplaySymbolTable() { 
       		cout << "Symbol Table Generated: " << endl;
		cout << "----------------------  " << endl;
		m_symtab.DisplaySymbolTable(); 
		cout << endl;
	}
    
        // Run emulator on the translation.
	void RunEmulator(){} //Tool to run the emulator
	
	struct MachineInstruct {
		int opCode;
		int loc;
		int symbolLoc;
		string MachineStringValue;
	};

private:
	FileAccess m_facc;	// File Access object
	SymbolTable m_symtab;	// Symbol table object
	Instruction m_inst;	// Instruction object
	emulator m_emul;        // Emulator 

	vector<MachineInstruct> m_placeMachineInstructionVector;
	MachineInstruct placeMachineInstructionStruct;
	stringstream machineStringStream;
	string machineString = "";
	int m_locTurn;
};
#endif

