/*
 * Thor - VM
 *
 * Entry Point
 *
 * Author: Balys Dapkunas, Dominykas Djacenka
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include <iostream>
#include "processor.h"
#include "memory.h"
#include "interface.h"

using namespace Thor::VM;

/* ============================================================================
 * E N T R Y   P O I N T
 * ============================================================================*/

int main(int argc, const char *argv[]){
	/*Processor *proc = new Processor();
	Interface interface(*proc);

	getch();

	Value v;
	for(int i = 0; i < THOR_BITS; i++){
		v.setBit(i, 1);
		proc->setRegister(Processor::RT_AX, v);
	}

	Value x("0a0b0c0d");
	proc->setRegister(Processor::RT_BX, x);

	Value y(1);
	proc->setRegister(Processor::RT_CX, y);

	proc->add(Processor::OT_Registers, Processor::RT_BX, Processor::RT_CX);
	proc->sub(Processor::OT_Registers, Processor::RT_BX, Processor::RT_CX);

	interface.refreshUI();
	interface.refreshUI();*/

	Memory mem(256, " !\"#");
	std::cout << std::hex << mem.getAddress(Value(0)).getInteger() << std::endl;
	mem.setAddress(Value(4),Value(0x123456));
	std::cout << mem.getAddress(Value(4)).getInteger() << std::endl;
	char *temp = new char[5];
	Value val = Value(0x20212223);
	memcpy(temp, val.getRepresentation(), 4);
	temp[5] = 0;
	std::cout << temp << std::endl;

	getch();
	return 0;
}
