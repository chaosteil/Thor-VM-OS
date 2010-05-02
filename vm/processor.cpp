/*
 * processor.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include <iostream>
#include "processor.h"

using namespace Thor::VM;

/* ============================================================================
 * T H O R : : V M : : P R O C E S S O R   C L A S S
 * ============================================================================*/

/* ============================================================================
 * P U B L I C   M E T H O D S
 * ============================================================================*/

Processor::Processor(Memory &memory)
	: _memory(memory)
{
}

Processor::~Processor(){
}

void Processor::cycle(){
	Value word = _getCommand();

	if(_parseCommand(word)){
	}else{
	}

	inc(RT_IP);
	dec(RT_TIME);
}

void Processor::setRegister(RegType type, const Value &value){
	_regs[type].setValue(value);
}

Value Processor::getRegister(RegType type) const{
	return _regs[type].getValue();
}

void Processor::add(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	Value x, y, z;

	_opBlockIn(x, y, op, left, right, vleft, vright);

	z.setInteger(x.getInteger() + y.getInteger());

	_opBlockOut(z, op, left, right, vleft, vright);
}

void Processor::sub(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	Value x, y, z;

	_opBlockIn(x, y, op, left, right, vleft, vright);

	z.setInteger(x.getInteger() - y.getInteger());

	_opBlockOut(z, op, left, right, vleft, vright);
}

void Processor::cmp(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	Value x, y, z;

	_opBlockIn(x, y, op, left, right, vleft, vright);

	z.setInteger(x.getInteger() - y.getInteger());
}

void Processor::inc(RegType reg){
	setRegister(reg, getRegister(reg).getInteger() + 1);
}

void Processor::dec(RegType reg){
	setRegister(reg, getRegister(reg).getInteger() - 1);
}

void Processor::andOp(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	Value x, y, z;

	_opBlockIn(x, y, op, left, right, vleft, vright);

	z.setInteger(x.getInteger() & y.getInteger());

	_opBlockOut(z, op, left, right, vleft, vright);
}

void Processor::orOp(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	Value x, y, z;

	_opBlockIn(x, y, op, left, right, vleft, vright);

	z.setInteger(x.getInteger() | y.getInteger());

	_opBlockOut(z, op, left, right, vleft, vright);
}

void Processor::xorOp(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	Value x, y, z;

	_opBlockIn(x, y, op, left, right, vleft, vright);

	z.setInteger(x.getInteger() ^ y.getInteger());

	_opBlockOut(z, op, left, right, vleft, vright);
}

void Processor::mov(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	Value x, y, z;

	_opBlockIn(x, y, op, left, right, vleft, vright);

	z.setInteger(y.getInteger());

	_opBlockOut(z, op, left, right, vleft, vright);
}

void Processor::nop(){
}

/* ============================================================================
 * P R I V A T E   M E T H O D S
 * ============================================================================*/

void Processor::_opBlockIn(Value &x, Value &y, OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	if(op == OT_Direct){
		x = getRegister(left);
		y = vright;
	}else if(op == OT_In){
		// TODO
	}else if(op == OT_Out){
		// TODO
	}else if(op == OT_Registers){
		x = getRegister(left);
		y = getRegister(right);
	}
}

void Processor::_opBlockOut(const Value &z, OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	if(op == OT_Direct){
		setRegister(left, z);
	}else if(op == OT_In){
		// TODO
	}else if(op == OT_Out){
		// TODO
	}else if(op == OT_Registers){
		setRegister(left, z);
	}
}

Processor::OpType Processor::_getOpType(char op) const{
	if(op == 'D')
		return OT_Direct;
	else if(op == '>')
		return OT_In;
	else if(op == '<')
		return OT_Out;
	else if(op == 'R')
		return OT_Registers;
	else
		return OT_None;
}

void Processor::_parseOp(const std::string &cmd, OpType &op, RegType &left, RegType &right, Value &vleft, Value &vright){
	op = _getOpType(cmd[1]);

	if(op == OT_Direct){
		left = _parseRT(cmd.c_str() + 2);	
		inc(RT_IP);
		vright = _getNumber().getInteger() & 0xFFFF0000;
		inc(RT_IP);
		vright = vright.getInteger() + ((_getNumber().getInteger() >> 16) & 0xFFFF);
	}else if(op == OT_In){
		// TODO
	}else if(op == OT_Out){
		// TODO
	}else if(op == OT_Registers){
		left = _parseRT(cmd.c_str() + 2);
		inc(RT_IP);
		Value v = _getCommand();
		right = _parseRT(v.getRepresentation());
	}else{
		// Error!
	}
}

Processor::RegType Processor::_parseRT(const std::string &cmd){
	if(!strncmp(cmd.c_str(), "AX", 2))
		return RT_AX;
	if(!strncmp(cmd.c_str(), "BX", 2))
		return RT_BX;
	if(!strncmp(cmd.c_str(), "CX", 2))
		return RT_CX;
	if(!strncmp(cmd.c_str(), "DX", 2))
		return RT_DX;
	if(!strncmp(cmd.c_str(), "R0", 2))
		return RT_R0;
	if(!strncmp(cmd.c_str(), "R1", 2))
		return RT_R1;
	else
		return RT_None;
}

Value Processor::_getCommand() const{
	Value address = _translatePage(getRegister(RT_CS).getInteger() + (getRegister(RT_IP).getInteger() >> 16));
	Value command(address.getInteger() + (getRegister(RT_IP).getInteger() & 0xFF));

	return _memory.getFromAddress(command.getInteger()*THOR_BYTES);
}

Value Processor::_getNumber() const{
	Value v(_getCommand().getRepresentation());

	return v;
}

Value Processor::_translatePage(const Value &pageaddress) const{
	Value ptr = getRegister(RT_PTR);
	Value address(ptr.getInteger() + pageaddress.getInteger());

	return _memory.getFromAddress(address.getInteger()*THOR_BYTES);
}

bool Processor::_parseCommand(const Value &word){
	std::string cmd(word.getRepresentation(), 4);

	OpType op;
	RegType left, right;
	Value vleft, vright;
	if(cmd[0] == '+'){
		_parseOp(cmd, op, left, right, vleft, vright);
		add(op, left, right, vleft, vright);
	}else if(cmd[0] == '-'){
		_parseOp(cmd, op, left, right, vleft, vright);
		sub(op, left, right, vleft, vright);
	}else if(cmd[0] == '?'){
		_parseOp(cmd, op, left, right, vleft, vright);
		cmp(op, left, right, vleft, vright);
	}else if(cmd[0] == '&'){
		_parseOp(cmd, op, left, right, vleft, vright);
		andOp(op, left, right, vleft, vright);
	}else if(cmd[0] == '|'){
		_parseOp(cmd, op, left, right, vleft, vright);
		orOp(op, left, right, vleft, vright);
	}else if(cmd[0] == '^'){
		_parseOp(cmd, op, left, right, vleft, vright);
		xorOp(op, left, right, vleft, vright);
	}else if(cmd[0] == 'M'){
		_parseOp(cmd, op, left, right, vleft, vright);
		mov(op, left, right, vleft, vright);
	}

	return true;
}
