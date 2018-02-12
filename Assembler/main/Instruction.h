// Class to manage instructions
//
#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <stdexcept>

#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace boost;

// The elements of an instruction.
class Instruction {

public:
 	   Instruction( ) { };
	  ~Instruction( ) { };

    // Codes to indicate the type of instruction we are processing. 
    enum InstructionType {
        ST_MachineLanguage, // A machine language instruction.
        ST_AssemblerInstr,  // Assembler Language instruction.
        ST_Comment,         // Comment or blank line
        ST_End              // end instruction.
    };
    // Record and parse the Instruction.
    InstructionType RecordInstruction( string &a_buff );

    // Compute the location of the next instruction.
    int LocationNextInstruction( int a_loc );

    // To access the label
    inline string &GetLabel( ) {
	    
        return m_Label;
    };
    // To determine if a label is blank.
    inline bool isLabel( ) {
        return ! m_Label.empty();
    };

	void setOpCodeValue(int opcodeValue){
		m_OpCode = opcodeValue;
	}
	int getOpCodeIntegerValue(){
		return m_OpCode;
	}
	string getOpCodeStringValue() {
		return m_OpCodeStringValue;
	}
	int getOperandValue(){
		return m_OperandValue;
	}
	string getOperand() {
		return m_Operand;
	}
	string getLeftVariableValue(){
		return m_LeftVariableValue;
	}
	string getRightVariableValue() {
		return m_RightVariableValue;
	}

	void instruction_identifier(const char * str);
	InstructionType GetCommentInstruction(string &a_comment);

	friend uint64_t constexpr mix(char m, uint64_t s);
	friend uint64_t constexpr flag(const char * m);
	friend inline bool isInteger(const std::string & s);

private:
		string m_Label;					// The label.
		string m_OpCodeStringValue;     // The symbolic op code.

		string m_OperandStringValue;
		string m_Operand;				// The operand.
		string m_instruction;			// The original instruction.
		string m_comment;

		int m_OpCode;				    // The numerical value of the OpCode.
		InstructionType m_type;			// The type of instruction.

		int m_OperandValue;				// The value of the operand if it is numeric. 
		int m_detLoc;
		
		string m_LeftVariableValue;
		string m_RightVariableValue;

};
#endif
