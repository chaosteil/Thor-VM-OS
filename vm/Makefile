#
# Compiles the Brains Server and Codename M
#

LD = g++
STRIP = strip
CPP = g++
INCLUDES = 
CFLAGS = -Wall -c -g $(INCLUDES)
LDFLAGS = -lncurses
PRGOUT = thorvm

# All Objects
SRC += $(wildcard *.cpp)
OBJECTS = $(SRC:.cpp=.o)

.cpp.o:
	$(CPP) $(CFLAGS) $< -o $@

all: $(PRGOUT)

clean:
	rm -rf $(OBJECTS)

$(PRGOUT): $(OBJECTS)
	$(LD) -o $(PRGOUT) $(OBJECTS) $(LDFLAGS)

.PHONY: all clean
