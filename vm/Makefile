#
# Compiles the Brains Server and Codename M
#

LD = g++
STRIP = strip
CPP = g++
INCLUDES = 
CFLAGS = -Wall -O2 -c -g $(INCLUDES)
LDFLAGS = 
PRGOUT = thorvm

# Entry Point
SUBDIRS = .

# All Objects
SRC += $(wildcard $(addsuffix /*.cpp, $(SUBDIRS)))
OBJECTS = $(SRC:.cpp=.o)

.cpp.o:
	$(CPP) $(CFLAGS) $< -o $@

all: $(PRGOUT)

clean:
	rm -rf $(OBJECTS)

$(PRGOUT): $(OBJECTS)
	$(LD) -o $(PRGOUT) $(OBJECTS) $(LDFLAGS)

.PHONY: all clean
