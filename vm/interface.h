#ifndef _THOR_VM_INTERFACE_H_
#define _THOR_VM_INTERFACE_H_

#include <ncurses.h>

#include "processor.h"

namespace Thor{
namespace VM{
	
	class Interface{
		public:
			Interface(Processor &processor);
			virtual ~Interface();
			
			void refreshUI();
		private:
			WINDOW *_createWindow(const char *title, int width, int height, int posx, int posy) const;
			void _deleteWindow(WINDOW *win);

			void _refreshRegisterWindow();
			Processor &_processor;

			WINDOW *_reg_win;
	};

}
}

#endif
