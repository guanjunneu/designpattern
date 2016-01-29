CC = gcc
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
LIBS = -lstdc++ -std=c++1y
INCLUDES = 
CXXFLAGS = -g -Wall -std=c++1y 

adaptor: $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS)

%.o : %.cpp
	$(CC) -c $< $(CXXFLAGS) 

.PHONY: clean
clean: 
	rm adaptor $(OBJS)
