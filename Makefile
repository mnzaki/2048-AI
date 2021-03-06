LDFLAGS=-lm
CFLAGS=-ggdb
FILES=search.cpp strategies.cpp problem_2048.cpp
INC=search.hpp strategies.hpp problem_2048.hpp

all: test project2048
test: problem_2048_test

problem_2048_test: $(FILES) $(INC) problem_2048_test.cpp
	g++ -std=c++11 $(CFLAGS) $(LDFLAGS) $(FILES) problem_2048_test.cpp -o problem_2048_test
project2048: $(FILES) $(INC) main.cpp
	g++ -std=c++11 $(CFLAGS) $(LDFLAGS) $(FILES) main.cpp -o project2048
