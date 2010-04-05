#ifndef _THOR_VM_PROCESSOR_H_
#define _THOR_VM_PROCESSOR_H_

#include "register.h"
#include "value.h"

namespace Thor{
namespace VM{

	class Processor{
		public:
			enum RegType{
				RT_CS = 0, RT_DS, RT_SS, RT_FLAGS, RT_TIME,
				RT_IP, RT_SP, RT_DI, RT_SI,
				RT_AX, RT_BX, RT_CX, RT_DX, RT_R0, RT_R1,
				RT_CIR, RT_COR, RT_CDR, RT_PTR
			};

			Processor();
			virtual ~Processor();

			void setRegister(RegType type, const Value &value);
			Value getRegister(RegType type) const;
			
		private:
			Register _regs[19];
	};

}
}

#endif
