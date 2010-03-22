/*
 * value.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include <string.h>
#include "value.h"

using namespace Thor::VM;

/* ============================================================================
 * T H O R : : V M : : V A L U E   C L A S S
 * ============================================================================*/

/* ============================================================================
 * P U B L I C   M E T H O D S
 * ============================================================================*/

Value::Value(unsigned int bytes)
	: _bytes(bytes), _value(new char[_bytes])
{
}

Value::~Value(){
	delete[] _value;
}

Value &Value::operator=(const Value &val){
	_bytes = val._bytes;
	
	delete[] _value;
	_value = new char[_bytes];
	memcpy(_value, val._value, _bytes);

	return *this;
}

void Value::setBit(unsigned int pos, char bit){
	// TODO
}

unsigned int Value::getSize() const{
	return _bytes * 8;
}

char Value::getBit(unsigned int pos) const{
	// TODO
	return 0;
}
