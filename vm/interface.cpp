/*
 * interface.cpp
 */

/* ============================================================================
 * I N C L U D E S
 * ============================================================================*/

#include <sstream>
#include "interface.h"

using namespace Thor::VM;

/* ============================================================================
 * T H O R : : V M : : I N T E R F A C E   C L A S S
 * ============================================================================*/

/* ============================================================================
 * P U B L I C   M E T H O D S
 * ============================================================================*/

Interface::Interface(Processor &processor)
	: _processor(processor),
	  _reg_win(NULL), _display_win(NULL)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();

	_reg_win = _createWindow("Registers", 16, 24, 0, 0);
	_display_win = _createWindow("Display", 80, 24, 16, 0);

	refreshUI();
}

Interface::~Interface(){
	endwin();
}

void Interface::refreshUI(){
	_refreshRegisterWindow();
}

/* ============================================================================
 * P R I V A T E   M E T H O D S
 * ============================================================================*/

WINDOW *Interface::_createWindow(const std::string &title, int width, int height, int posx, int posy) const{
	WINDOW *win;

	win = newwin(height, width, posy, posx);
	box(win, 0 , 0);
	wrefresh(win);

	_setTitle(win, title);

	return win;
}

void Interface::_setTitle(WINDOW *win, const std::string &title) const{
	mvwprintw(win, 0, 1, title.c_str());
}

void Interface::_deleteWindow(WINDOW *win) const{
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
}

void Interface::_refreshRegisterWindow() const{
	mvwprintw(_reg_win, 1, 1, "CS: 0x%08X", _processor.getRegister(Processor::RT_CS).getInteger());
	mvwprintw(_reg_win, 2, 1, "DS: 0x%08X", _processor.getRegister(Processor::RT_DS).getInteger());
	mvwprintw(_reg_win, 3, 1, "SS: 0x%08X", _processor.getRegister(Processor::RT_SS).getInteger());
	mvwprintw(_reg_win, 4, 1, "FL: 0x%08X", _processor.getRegister(Processor::RT_FLAGS).getInteger());
	mvwprintw(_reg_win, 5, 1, "TI: 0x%08X", _processor.getRegister(Processor::RT_TIME).getInteger());
	mvwprintw(_reg_win, 7, 1, "IP: 0x%08X", _processor.getRegister(Processor::RT_IP).getInteger());
	mvwprintw(_reg_win, 8, 1, "SP: 0x%08X", _processor.getRegister(Processor::RT_SP).getInteger());
	mvwprintw(_reg_win, 9, 1, "DI: 0x%08X", _processor.getRegister(Processor::RT_DI).getInteger());
	mvwprintw(_reg_win, 10, 1, "SI: 0x%08X", _processor.getRegister(Processor::RT_SI).getInteger());
	mvwprintw(_reg_win, 12, 1, "AX: 0x%08X", _processor.getRegister(Processor::RT_AX).getInteger());
	mvwprintw(_reg_win, 13, 1, "BX: 0x%08X", _processor.getRegister(Processor::RT_BX).getInteger());
	mvwprintw(_reg_win, 14, 1, "CX: 0x%08X", _processor.getRegister(Processor::RT_CX).getInteger());
	mvwprintw(_reg_win, 15, 1, "DX: 0x%08X", _processor.getRegister(Processor::RT_DX).getInteger());
	mvwprintw(_reg_win, 16, 1, "R0: 0x%08X", _processor.getRegister(Processor::RT_R0).getInteger());
	mvwprintw(_reg_win, 17, 1, "R1: 0x%08X", _processor.getRegister(Processor::RT_R1).getInteger());
	mvwprintw(_reg_win, 19, 1, "CI: 0x%08X", _processor.getRegister(Processor::RT_CIR).getInteger());
	mvwprintw(_reg_win, 20, 1, "CO: 0x%08X", _processor.getRegister(Processor::RT_COR).getInteger());
	mvwprintw(_reg_win, 21, 1, "CD: 0x%08X", _processor.getRegister(Processor::RT_CDR).getInteger());
	mvwprintw(_reg_win, 22, 1, "PT: 0x%08X", _processor.getRegister(Processor::RT_PTR).getInteger());
	wrefresh(_reg_win);
}

void Interface::_refreshDisplayWindow() const{
	wrefresh(_display_win);
}
