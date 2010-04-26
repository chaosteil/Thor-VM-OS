#ifndef _THOR_VM_REGISTER_H_
#define _THOR_VM_REGISTER_H_

#include "value.h"

namespace Thor{
namespace VM{

	class Register{
		public:
			Register();
			virtual ~Register();

			void setValue(const Value &value);
			const Value &getValue() const;

			void add(const Value &value);

		private:
			Value _value;
	};

}
}

#endif
