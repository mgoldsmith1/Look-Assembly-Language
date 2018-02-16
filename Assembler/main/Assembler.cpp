//
//      Implementation of the Assembler class.
//
#include "stdafx.h"
#include "Assembler.h"
#include "Errors.h"
#include <vector>

// Constructor for the assembler.
Assembler::Assembler(int argc, char *argv[]) : m_facc(argc, argv)
{
	// Nothing else to do here.
}
// Destructor currently does nothing.  You might need to add something.
Assembler::~Assembler()
{
}
// Pass I establishes the location of the labels.  You will do a better function comments.
void Assembler::PassI()
{
	cout << endl;
	cout << "To Build the Look Assembly Code" << endl;
	system("pause");
	cout << endl;
	cout << "Building..." << endl;

	 // Tracks the location of the instructions to be generated.
	int loc = 0;       
	
	// Successively process each line of source code.
	for (; ; ) {

		// Read the next line from the source file.
		string buff;
		if (!m_facc.GetNextLine(buff)) {

			// If there are no more lines, we are missing an end statement.
			// We will let this error be reported by Pass II.	    
			m_facc.rewind();
		}
		// Parse the line and get the instruction type.
		Instruction::InstructionType st = m_inst.RecordInstruction(buff);

		if (st == Instruction::ST_AssemblerInstr) {
			if (!m_inst.getOperand().empty() && m_inst.getOperand() != "det") {
				m_emul.insertMemory(loc, m_inst.getOperandValue());
				m_symtab.AddSymbol(m_inst.getLeftVariableValue(), loc - 1);
				m_symtab.AddSymbol(m_inst.getRightVariableValue(), loc - 1);
			}
		}
		if (st == Instruction::ST_MachineLanguage) {
			m_emul.insertMemory(loc - 1, m_inst.getOpCodeIntegerValue());
			if(m_inst.getOpCodeStringValue() != m_inst.getLeftVariableValue())
				m_symtab.AddSymbol(m_inst.getLeftVariableValue(), loc - 1);
		}
		if (st == Instruction::ST_End) { 
			cout << "Build Complete..." << endl;
			cout << endl;
		}

		// If this is an end statement, there is nothing left to do in pass I.
		// Pass II will determine if the end is the last statement.
		if (st == Instruction::ST_End) return;

		// Labels can only be on machine language and assembler language instructions.
		if (st != Instruction::ST_MachineLanguage && st != Instruction::ST_AssemblerInstr) continue;

		// If the instruction has a label, record it and its location in the symbol table. 
		if (m_inst.isLabel()) {
			Feed(m_inst.getOpCodeIntegerValue(), loc - 1, loc - 1);
		}
		else {
			Feed(m_inst.getOpCodeIntegerValue(), loc - 1, 0);
		}
		// Compute the location of the next instruction.
		loc = m_inst.LocationNextInstruction(loc);
	}
}
void Assembler::PassII() {
	cout << endl;
	cout << "To Run the Look Assembly Code:" << endl;
	system("pause");
	cout << endl;
	cout << "Machine Translation of the program: " << endl;
	cout << "----------------------------------  " << endl;
	for (int i = 0; i < m_placeMachineInstructionVector.size(); ++i) {
		cout << "Address " << m_placeMachineInstructionVector[i].loc
		     << ": "       << m_placeMachineInstructionVector[i].MachineStringValue << "" << endl;
	}
	system("pause");
}
void Assembler::Feed(int opCode, int loc, int symbolLoc) {
	machineStringStream.str(string());
	machineStringStream << setfill('0') << setw(2) << opCode;
	machineStringStream << setfill('0') << setw(4) << loc;
	machineString = machineStringStream.str();
	placeMachineInstructionStruct.MachineStringValue = machineString;
	placeMachineInstructionStruct.opCode = stoi(machineString.c_str());
	placeMachineInstructionStruct.loc = int(loc);
	m_placeMachineInstructionVector.push_back(placeMachineInstructionStruct);
}


