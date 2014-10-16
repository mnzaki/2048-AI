LDFLAGS=-lm
CFLAGS=-O3
FILES=search.cpp strategies.cpp problem_2048.cpp
INC=search.hpp strategies.hpp problem_2048.hpp

test: problem_2048_test

problem_2048_test: $(FILES) $(INC) problem_2048_test.cpp
	g++ $(CFLAGS) $(LDFLAGS) $(FILES) problem_2048_test.cpp -o problem_2048_test
