COMPILE_DIR = $(shell pwd |sed 's/^\(.*\)[/]//' )
CC = gcc
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
LIBS = -lstdc++ -std=c++1y
INCLUDES = 
CXXFLAGS = -g -Wall -std=c++1y 

$(COMPILE_DIR) : $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS)

%.o : %.cpp
	$(CC) -c $< $(CXXFLAGS) 

.PHONY: clean
clean: 
	rm  $(COMPILE_DIR) $(OBJS)
