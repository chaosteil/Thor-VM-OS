/*
 * value.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include <string.h>
#include <cmath>
#include "value.h"

using namespace Thor::VM;

/* ============================================================================
 * T H O R : : V M : : V A L U E   C L A S S
 * ============================================================================*/

/* ============================================================================
 * P U B L I C   M E T H O D S
 * ============================================================================*/

Value::Value(int def, unsigned int bytes)
	: _bytes(bytes), _value(new char[_bytes])
{
	setInteger(def);
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
	// TODO test it
	int byte = floor(pos / 8); 
	int bits = pos % 8;

	if(bit != 0){
		_value[byte] = _value[byte] | ( 1 << bits);
	}else{
		_value[byte] = ~((~_value[byte]) | ( 1 << bits));
	}
}

void Value::setInteger(int value){
	*_value = value;
}

unsigned int Value::getSize() const{
	return _bytes * 8;
}

char Value::getBit(unsigned int pos) const{
	// TODO
	return 0;
}
