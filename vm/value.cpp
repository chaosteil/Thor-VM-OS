/*
 * value.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include <iostream>
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

Value::Value(int def){
	setInteger(def);
}

Value::Value(const std::string &val){
	for(int i = THOR_BYTES-1; i >= 0; i--){
		int low = _convertFromAscii(val[i*2 +1]),
			high = _convertFromAscii(val[i*2]);

		_value[i] = ((high << 4) | low);
	}
}

Value::~Value(){
}

void Value::setBit(unsigned int pos, char bit){
	int byte = (THOR_BYTES-1) - floor(pos / 8); 
	int bits = pos % 8;

	if(bit != 0){
		_value[byte] |= 1 << bits;
	}else{
		_value[byte] = ~((~_value[byte]) | ( 1 << bits));
	}
}

void Value::setInteger(unsigned int value){
	for(int i = 0; i < THOR_BYTES; i++){
		_value[i] = value >> (i * 8);
	}
}

unsigned int Value::getSize() const{
	return THOR_BYTES * 8;
}

char Value::getBit(unsigned int pos) const{
	int byte = (THOR_BYTES-1) - floor(pos / 8); 
	int bits = pos % 8;

	if((_value[byte] | bits) != 0)
		return 1;

	return 0;
}

unsigned int Value::getInteger() const{
	unsigned int x = 0;

	for(int i = 0; i < THOR_BYTES; i++){
		x |= (0xFF & _value[i]) << ((THOR_BYTES-1 - i)*8);
	}

	return x;
}

/* ============================================================================
 * P R I V A T E   M E T H O D S
 * ============================================================================*/

char Value::_convertFromAscii(char x){
	if(x >= '0' && x <= '9')
		return x-'0';
	
	if(x >= 'a' && x <= 'f')
		return x-'a'+10;

	if(x >= 'A' && x <= 'F')
		return x-'A'+10;

	return 0;
}
