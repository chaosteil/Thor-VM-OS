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

Processor::Processor(){
}

Processor::~Processor(){
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
