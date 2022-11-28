//
//      Implementation of the Instruction class.
//
#include "stdafx.h"
#include "Instruction.h"
#include "Errors.h"

Instruction::InstructionType Instruction::ParseInstruction(string a_line)
{
	cout << "ParseInstruction - In Progress (Not done yet)" << endl;
	m_instruction = a_line;

	// Remove any comments.
	RemoveComment(a_line);

	// Parse the line.
	bool rv = ParseLine(a_line, m_Label, m_OpCode, m_Operand);

	// Errors
	/*
		if(!m_Label.empty() && m_OpCode.empty()){
			Errors::RecordError("Quack");
		}
	*/

	return ST_MachineLanguage;
}

void Instruction::RemoveComment(string& a_line) 
{
	size_t pos = a_line.find(';');
	if (pos == string::npos) return;

	a_line.erase(pos);
}


bool Instruction::ParseLine(const string& a_line, string& a_label, string& a_opcode, string& a_operand) 
{
	a_label = a_opcode = a_operand = "";

	if (a_line.empty()) 
	{
		return true;
	}

	istringstream ins(a_line);
	if (a_line[0] != ' ' && a_line[0] != '\t')
	{
		ins >> a_label;
	}

	string temp;
	ins >> a_opcode >> a_operand >> temp;

	return temp == "";
}