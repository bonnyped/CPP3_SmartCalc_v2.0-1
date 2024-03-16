CC 				= g++ -std=c++17 -g -pedantic
CCFLAGS 		= -Wall -Werror -Wextra -fno-stack-protector
TEST_FLAGS  	=  -lgtest -pthread -std=c++17  -lstdc++ -lpthread -lm
GFLAGS      	= -fprofile-arcs -ftest-coverage
PREF_MODEL 		= "./s21_smart_calc_v_2_0/model/"
PREF_CONTROLLER = "./s21_smart_calc_v_2_0/controller/"
PREF_VIEW		= "./s21_smart_calc_v_2_0/view/"
PREF_TEST 		= "tests/"
OS         		=  $(shell uname -s)

all: clang compile  

clang: 
	clang-format --style=GOOGLE -i $(PREF_MODEL)*.cc $(PREF_MODEL)*.h $(PREF_CONTROLLER)*.cc $(PREF_CONTROLLER)*.h $(PREF_VIEW)*.cpp $(PREF_VIEW)*.h  $(PREF_TEST)*.cc $(PREF_TEST)*.h

compile:
	$(CC) main.cpp $(PREF_MODEL)*.cc $(CCFLAGS)
	./a.out

install:
	@cd ./s21_smart_calc_v_2_0/ && cmake .
	@cd ./s21_smart_calc_v_2_0/ && make
	cd ..
	mkdir run/
	cp ./s21_smart_calc_v_2_0/./s21smc ./run/
	run/./s21smc

uninstall:
	@rm -rf ./run
	@cd ./s21_smart_calc_v_2_0/ && make clean

.dvi:
	doxygen gendoc_s21snc
ifeq ($(OS),Linux) 
	xdg-open documentation/html/annotated.html
else
	open -a "Google Chrome" documentation/html/annotated.html
endif

dist:

tests: clean
	$(CC) -o $(PREF_TEST)test $(CCFLAGS) $(PREF_TEST)*.cc $(PREF_MODEL)*.cc $(PREF_CONTROLLER)*.cc $(TEST_FLAGS)
	$(PREF_TEST)test

gcov: 
	$(CC) -o $(PREF_TEST)test $(PREF_TEST)*.cc $(PREF_MODEL)*.cc $(PREF_CONTROLLER)*.cc $(TEST_FLAGS) $(GFLAGS)
	$(PREF_TEST)test


lcov: gcov
	lcov --quiet --no-recursion --capture --directory $(PREF_TEST) --output-file $(PREF_TEST)test.info
	@lcov --quiet --no-recursion -r $(PREF_TEST)test.info '/usr/*' '*/v1/*' '*/tests/*' '*/s21_smart_calc_v_2_0/controller/*' --output-file $(PREF_TEST)test.info
	genhtml -o ./report/ $(PREF_TEST)test.info
	@rm -f $(PREF_TEST)*.gcda  $(PREF_TEST)*.gcno
	@rm -f $(PREF_TEST)test.info
ifeq ($(OS),Linux) 
	xdg-open report/index.html
else
	open -a "Google Chrome" report/index.html
endif
	@rm -rf ./report $(PREF_TEST)test

clean:
	rm -rf ./a.out $(PREF_TEST)test ./documentation