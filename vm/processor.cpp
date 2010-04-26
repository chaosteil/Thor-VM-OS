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
	if(op == OT_Direct){
		int x = getRegister(left).getInteger() + vright.getInteger();
		setRegister(left, Value(x));
	}else if(op == OT_In){
		// TODO
	}else if(op == OT_Out){
		// TODO
	}else if(op == OT_Registers){
		int x = getRegister(left).getInteger() + getRegister(right).getInteger();
		setRegister(left, Value(x));
	}
}

void Processor::sub(OpType op, RegType left, RegType right, const Value &vleft, const Value &vright){
	if(op == OT_Direct){
		int x = getRegister(left).getInteger() - vright.getInteger();
		setRegister(left, Value(x));
	}else if(op == OT_In){
		// TODO
	}else if(op == OT_Out){
		// TODO
	}else if(op == OT_Registers){
		int x = getRegister(left).getInteger() - getRegister(right).getInteger();
		setRegister(left, Value(x));
	}
}
