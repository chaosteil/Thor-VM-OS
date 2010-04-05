/*
 * processor.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

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
