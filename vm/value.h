#ifndef _THOR_VM_VALUE_H_
#define _THOR_VM_VALUE_H_

namespace Thor{
namespace VM{

#define THOR_BITS 32
#define THOR_BYTES (THOR_BITS/8)
	/**
	 * 4 bytes value for registers.
	 */
	class Value{
		public:
			Value(int def = 0);
			virtual ~Value();

			void setBit(unsigned int pos, char bit);
			void setInteger(unsigned int value);

			unsigned int getSize() const; /**< Returns the value in bitsize */
			char getBit(unsigned int pos) const; /**< Returns the value of the bit at the specified position, starting from the lowest one. */
			unsigned int getInteger() const;

		private:
			char _value[THOR_BYTES];
	};

}
}

#endif
