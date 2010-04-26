#ifndef _THOR_VM_MEMORY_H_
#define _THOR_VM_MEMORY_H_

#include <cstring>
#include "value.h"

namespace Thor{
namespace VM{

class Memory{
	public:
		Memory(const int size, const char *init = "");
		virtual ~Memory();

		const Value getAddress(const Value &address) const;
		void setAddress(const Value &address, const Value &value);

	private:
		const int _size;
		char *_memory;

};

}
}

#endif
