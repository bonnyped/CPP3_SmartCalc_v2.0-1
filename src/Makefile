CC = g++ -std=c++17 -g -pedantic
CCFLAGS = -Wall -Werror -Wextra -fno-stack-protector
TEST_FLAGS  =  -lgtest -pthread -std=c++17  -lstdc++ -lpthread -lm

all: clang compile run 

clang: 
	clang-format --style=GOOGLE -i *.cc *.cpp *.h ./tests/*.cc ./tests/*.h

compile:
	$(CC) *.cc main.cpp $(CCFLAGS)
	
run:	
	./a.out

test:
	rm -rf ./tests/test
	$(CC) -o ./tests/test $(CCFLAGS) ./tests/*.cc ./*.cc $(TEST_FLAGS)
	./tests/test
	# make lcov

clean:
	rm -rf ./a.out ./tests/test