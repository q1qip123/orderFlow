INCLUDE = -I./standalone -I$(OSPL_HOME)/examples/include -I$(OSPL_HOME)/include/dcps/C++/SACPP -I./src
LDFLAGS = -L$(OSPL_HOME)/lib
LDLIBS = -ldcpssacpp -lddskernel

test = $(CURDIR)

TYPE_SRC = $(shell ls standalone/*.cpp)
SRC = $(shell ls src/*.cpp)
all: waiter kitchen 

waiter:
	g++ -std=c++11  Waiter.cpp $(SRC) $(TYPE_SRC) $(LDFLAGS) $(LDLIBS) $(INCLUDE) -lpthread -o waiter
kitchen:
	g++ -std=c++11 Kitchen.cpp $(SRC) $(TYPE_SRC) $(LDFLAGS) $(LDLIBS) $(INCLUDE)  -lpthread -o kitchen

