
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
RM = rm -f

all: main

run: main
	./main

run_test: test
	./test

main: main.o complex.o
	$(CXX) $(CXXFLAGS) -o main main.o complex.o $(LDFLAGS)

test: test.o complex.o
	$(CXX) $(CXXFLAGS) -o test test.o complex.o $(LDFLAGS)

main.o: main.cpp tree.hpp node.hpp iterators.hpp complex.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp TestCounter.cpp tree.hpp node.hpp iterators.hpp complex.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

complex.o: complex.cpp complex.hpp
	$(CXX) $(CXXFLAGS) -c complex.cpp

clean:
	$(RM) main test *.o

.PHONY: all run clean run_test

