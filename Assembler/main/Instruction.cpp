//Implementation of the Instruction Class


#include "stdafx.h"
#include "Instruction.h" 
#include "Errors.h" 

uint64_t constexpr mix(char m, uint64_t s)
{
	return ((s << 7) + ~(s >> 3)) + ~m;
}
uint64_t constexpr flag(const char * m)
{
	return (*m) ? mix(*m, flag(m + 1)) : 0;
}
void Instruction::instruction_identifier(const char * str)
{
	switch (flag(str)) 
	{
		/////////////////////////////////////////////////////////////////////////////
		///////////////////////////// Operands //////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////
		case flag("det"): 
							m_type = InstructionType::ST_AssemblerInstr;
							m_Operand = "det";
							break;

		case flag("declare"): 
							m_type = InstructionType::ST_AssemblerInstr;
							m_Operand = "declare";
							break;
		case flag("ds"):
							m_type = InstructionType::ST_AssemblerInstr;
							m_Operand = "ds"; 
							break;
		case flag("end"):
							m_type = InstructionType::ST_End;
							m_Operand = "end";
							break;

		/////////////////////////////////////////////////////////////////////////////
		////////////////////////////// OpCodes //////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////

		case flag("add"): 
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "add";
							m_OpCode = 01;
							break;

		case flag("sub"): 
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "sub";
						    m_OpCode = 02;
							break;
		case flag("mult"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "mult";
							m_OpCode = 03;
							break;
		case flag("div"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "div";
							m_OpCode = 04;
							break;
		case flag("pack"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "pack";
							m_OpCode = 05;
							break;

		case flag("acc"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "acc";
							m_OpCode = 06;
							break;

		case flag("look"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "look";
							m_OpCode = 07;
							break;

		case flag("write"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "write";
							m_OpCode = 8;
							break;

		case flag("b"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "b";
							m_OpCode = 9;
							break;
		case flag("bm"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "bm";
							m_OpCode = 10;
							break;
		case flag("bz"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "bz";
							m_OpCode = 11;
							break;
		case flag("bp"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "bp";
							m_OpCode = 12;
							break;
		case flag("halt"):
							m_type = InstructionType::ST_MachineLanguage;
							m_OpCodeStringValue = "halt";
							m_OpCode = 13;
							break;
		
		default:			
				m_Label = str;
				if (!m_Label.empty() && !m_Label.find_first_of(";")) {
					GetLabel() = str;
					m_type = InstructionType::ST_Comment;
					break;
				}
				else {
		
				}

				break;
	};

}
inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}
Instruction::InstructionType Instruction::GetCommentInstruction(string &a_comment) {

	//getline(cin, a_comment); //text

	if (a_comment.find_first_of(";") == string::npos)
	{
		m_comment = a_comment;//.substr(0, 1);
		m_type = InstructionType::ST_Comment;
		
	}
    return m_type;
}

// Record and parse the Instruction.
Instruction::InstructionType Instruction::RecordInstruction(string &a_buff)
{
	string temp, first, last;
	stringstream instructionStream(a_buff);
	const int MAX_INSTRUCTIONS = 100;
	string instructionLineArray[MAX_INSTRUCTIONS]; //100
 	int i = 0;

	while (instructionStream.good()) {
		instructionStream >> instructionLineArray[i];
		++i;
	}
	for (i = 0; i < 3; ++i) {
		temp = instructionLineArray[i];
		if (isInteger(temp) == true)
		{
			if (m_Operand == "det")
			{
				m_OperandValue = atoi(instructionLineArray[i].c_str());
				m_detLoc = m_OperandValue;
			}
			if (m_Operand == "declare")
			{
				m_OperandValue = atoi(instructionLineArray[i].c_str());
			}
			if (m_Operand == "ds")
			{
				m_OperandValue = atoi(instructionLineArray[i].c_str());
			}
		}
		else {
			const char * c = temp.c_str();
			instruction_identifier(c);
		}
	}

	//Gets the variable from both the left and right hand side of the instruction
	if (!m_OpCodeStringValue.empty()) {
		first = instructionLineArray[i - 3].c_str();
		last = instructionLineArray[i - 1].c_str();
		m_LeftVariableValue = first;
		m_RightVariableValue = last;
	}
	return m_type;
}

int Instruction::LocationNextInstruction(int a_loc)
{
	if (m_detLoc != 0) {
		a_loc = m_detLoc;
		m_detLoc = 0;
	}
	return a_loc + 1;
}
/*
Symbol #     Symbol     Location
0                 a               207
1                 b               206
2                 hay             102
3                 hi              100
4                 x               106
5                 y               107
________________________________________________________

*/
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/*
This is roughly how this program should be interperated:
________________________________________________________

Press Enter to continue...

Translation of Program:

Location    Contents    Original Statement
0                                det     100
100          000005     x        declare  5
101                     y        declare  88
206          000555     b        declare  555
207          000100     a        declare  100
												;this is a test

100          070100     hi       look     x     ;comment immediately after statement
101          050100              pack     x
102          060101     hey      acc      y     ;This will accumulate the contents of y which is hey
103          080100              write    x
104          120100              bp       hi
105          130000              halt
												; test

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
*/