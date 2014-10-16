LDFLAGS=-lm
CFLAGS=-O3
FILES=search.cpp strategies.cpp problem_2048.cpp

test: problem_2048_test

problem_2048_test:
	g++ $(CFLAGS) $(LDFLAGS) $(FILES) problem_2048_test.cpp -o problem_2048_test
