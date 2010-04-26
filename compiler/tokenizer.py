class Tokenizer:
	def __init__(self, file):
		self.stream = file

	def getTell(self):
		return self.stream.tell()

	def getNextToken(self):
		state = 'n'
		token = None
		char = self.stream.read(1)
		while char != '':
			if state == '$':     #string value
				if char != '"':
					token.value += char
				else:
					return token
			elif state == 's':   #string
				if not self.isWhitespace(char):
					if not self.isString(char):
						raise ValueError("str", self.stream.tell())
					else:
						token.value += char.upper()
				else:
					return token
			elif state == 'x':   #hexadecimal
				if not self.isWhitespace(char):
					if not self.isHexadecimal(char):
						raise ValueError("hex", self.stream.tell())
					else:
						token.value *= 16
						token.value += int(char, 16)
				else:
					return token
			elif state == 'd':   #decimal
				if not self.isWhitespace(char):
					if not self.isDecimal(char):
						raise ValueError("dec", self.stream.tell())
					else:
						token.value *= 10
						token.value += int(char)
				else:
					return token
			elif state == 'c':   #comment
				if char == '\n':
					state = 'n'
				else:
					pass
			elif state == 'n':   #no state
				if char == '#':
					state = 'c'
				elif char == '"':
					state = '$'
					token = Token('l', "")
				elif char == '0':
					char = stream.read(1)
					if char == 'x':
						state = 'x'
						token = Token('n', 0)
					elif char == 'd':
						state = 'd'
						token = Token('n', 0)
					elif isDecimal(char):
						state = 'd'
						token = Token('n', int(char))
					else:
						raise ValueError("num", self.stream.tell())
				elif isDecimal(char):
					state = 'd'
					token = Token('n', int(char))
				elif isSymbol(char):
					token = Token('$', char)
					return token
				elif isString(char):
					state = 's'
					token = Token('s', char.upper())
				else:
					raise ValueError("non", self.stream.tell())
			char = self.stream.read(1)
		return None

	def	isWhitespace(self, char):
		return char in " \n\t"
	
	def isHexadecimal(self, char):
		return char.lower() in "0123456789abcdef"

	def isDecimal(self, char):
		return char in "0123456789"

	def isString(self, char):
		return char.lower() in "qwertyuiopasdfghjklzxcvbnm0123456789_"

	def isSymbol(self, char):
		return char in ".,[]:+-"

class Token:
	def __init__(self, type, value):
		self.type = type
		self.value = value

	def getValue(self):
		return self.value

	def getType(self):
		return self.type
	

class ValueError(Exception):
	def __init__(self, type, pos):
		self.type = type
		self.position = pos
