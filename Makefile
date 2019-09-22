INCLUDE = -I./standalone -I$(OSPL_HOME)/examples/include -I$(OSPL_HOME)/include/dcps/C++/SACPP
LDFLAGS = -L$(OSPL_HOME)/lib
LDLIBS = -ldcpssacpp -lddskernel

test = $(CURDIR)

TYPE_SRC = $(shell ls standalone/*.cpp)
all: waiter kitchen

waiter:
	@echo $(TYPE_SRC)
	g++ src/waiter.cpp $(TYPE_SRC) $(LDFLAGS) $(LDLIBS) $(INCLUDE)  -o waiter
kitchen:
	g++ src/kitchen.cpp $(TYPE_SRC) $(LDFLAGS) $(LDLIBS) $(INCLUDE) -o kitchen
