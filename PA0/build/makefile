all: Key.o solver

Key.o: ../include/Key.h ../src/Key.cpp
	g++ -c ../src/Key.cpp -o ../bin/Key.o -I../include

solver: ../src/main.cpp ../bin/eval.o ../bin/Key.o
	g++ -o solver ../src/main.cpp ../bin/eval.o ../bin/Key.o -I../include

clean:
	rm -rf solver ../bin/Key.o
