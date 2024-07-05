
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
RM = rm -f

all: main

run: main
	./main


main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o $(LDFLAGS)

main.o: main.cpp tree.hpp node.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	$(RM) main main.o

.PHONY: all run clean 

