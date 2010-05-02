/*
 * memory.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include "memory.h"

using namespace Thor::VM;

/* ============================================================================
 * T H O R : : V M : : M E M O R Y    C L A S S
 * ============================================================================*/

/* ============================================================================
 * P U B L I C   M E T H O D S
 * ============================================================================*/

Memory::Memory(const int size, const char *init, int initsize): _size(size), _memory(new char[size]){
	memset(_memory, 0, _size);
	memcpy(_memory, init, initsize);
}

Memory::~Memory(){
}

const Value Memory::getFromAddress(const Value &address) const{
	char stringRep[5] = "\0\0\0\0";
	memcpy(stringRep, _memory + address.getInteger(), 4);
	return Value(stringRep, true);
}

void Memory::setToAddress(const Value &address, const Value &value){
	memcpy(_memory + address.getInteger(), value.getRepresentation(), THOR_BYTES);
}
