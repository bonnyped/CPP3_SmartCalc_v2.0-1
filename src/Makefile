CC = g++ -std=c++17 -g -pedantic
CCFLAGS = -Wall -Werror -Wextra -fno-stack-protector
TEST_FLAGS  =  -lgtest -pthread -std=c++17  -lstdc++ -lpthread -lm
PREF_MODEL = "./s21_smart_calc_v_2_0/model/"
PREF_CONTROLLER = "./s21_smart_calc_v_2_0/controller/"
PREF_VIEW = "./s21_smart_calc_v_2_0/view/"
PREF_TEST = "./tests/"

all: clang compile  

clang: 
	clang-format --style=GOOGLE -i $(PREF_MODEL)*.cc $(PREF_MODEL)*.h $(PREF_CONTROLLER)*.cc $(PREF_CONTROLLER)*.h $(PREF_VIEW)*.cpp $(PREF_VIEW)*.h  $(PREF_TEST)*.cc $(PREF_TEST)*.h

compile:
	$(CC) main.cpp $(PREF_MODEL)*.cc $(CCFLAGS)
	
run:	
	./a.out

test:
	rm -rf ./tests/test
	$(CC) -o ./tests/test $(CCFLAGS) ./tests/*.cc $(PREF_MODEL)*.cc $(TEST_FLAGS)
	./tests/test
	# make lcov

clean:
	rm -rf ./a.out ./tests/test