all: clean solver

run: all

runinterractive: all
	python3 interactive_runner.py python3 local_testing_tool.py 1 -- ./solver

solver: main.cpp
	g++ -g -DLOCAL_DEBUG -std=c++17 -o solver main.cpp

clean:
	$(RM) solver