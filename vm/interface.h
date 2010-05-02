#ifndef _THOR_VM_INTERFACE_H_
#define _THOR_VM_INTERFACE_H_

#include <ncurses.h>
#include <string>

#include "processor.h"
#include "memory.h"

namespace Thor{
namespace VM{
	
	class Interface{
		public:
			Interface(Processor &processor);
			virtual ~Interface();
			
			void refreshUI();

		private:
			WINDOW *_createWindow(const std::string &title, int width, int height, int posx, int posy) const;
			void _setTitle(WINDOW *win, const std::string &title) const;
			void _deleteWindow(WINDOW *win) const;

			void _refreshRegisterWindow() const;
			void _refreshDisplayWindow() const;

			Processor &_processor;

			WINDOW *_reg_win, *_display_win;
	};

}
}

#endif
