/*
 * memory.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include "memory.h"
#include <iostream>

using namespace Thor::VM;

/* ============================================================================
 * T H O R : : V M : : M E M O R Y    C L A S S
 * ============================================================================*/

/* ============================================================================
 * P U B L I C   M E T H O D S
 * ============================================================================*/

Memory::Memory(const int size, const char *init): _size(size), _memory(new char[size]){
	memset(_memory, 0, _size);
	memcpy(_memory, init, strlen(init));
}

Memory::~Memory(){
}

const Value Memory::getAddress(const Value &address) const{
	return Value(*(int*)(void*)(_memory + address.getInteger()));
}

void Memory::setAddress(const Value &address, const Value &value){
	memcpy(_memory + address.getInteger(), value.getRepresentation(), THOR_BYTES);
}
