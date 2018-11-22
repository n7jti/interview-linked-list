CC=gcc
CXX=g++
RM=rm -f

CPPUTEST_HOME=./../cpputest

CXXFLAGS=-g -I $(CPPUTEST_HOME)/include -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h 
LDFLAGS=-g 
LDLIBS=-L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

SRCS= linkedlist.cpp list.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: linkedlist

linkedlist: $(OBJS)
	$(CXX) $(LDFLAGS) -o linkedlist $(OBJS) $(LDLIBS) 

linkedlist.o: linkedlist.cpp list.h

list.o: list.cpp list.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) linkedlist
