#ifndef _THOR_VM_VALUE_H_
#define _THOR_VM_VALUE_H_

namespace Thor{
namespace VM{

	class Value{
		public:
			Value(int def = 0, unsigned int bytes = 4);
			virtual ~Value();
			Value &operator=(const Value &val);

			void setBit(unsigned int pos, char bit);
			void setInteger(int value);

			unsigned int getSize() const; /**< Returns the value in bitsize */
			char getBit(unsigned int pos) const; /**< Returns the value of the bit at the specified position, starting from the lowest one. */

		private:
			unsigned int _bytes;
			char *_value;
	};

}
}

#endif
