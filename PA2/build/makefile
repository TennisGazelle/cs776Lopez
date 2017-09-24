CC=mpic++
CXXFLAGS=-Wall -std=c++11 -g
LIBS=-lpmi
INCLUDES=-I../include

all: ../bin/Key.o solver

../bin/Key.o: ../include/Key.h ../src/Key.cpp
	$(CC) $(CXXFLAGS) -c ../src/Key.cpp -o ../bin/Key.o $(INCLUDES)

solver: ../src/main.cpp ../bin/evalCPP.o ../bin/Key.o
	$(CC) $(CXXFLAGS) -o solver ../src/main.cpp ../bin/evalCPP.o ../bin/Key.o $(INCLUDES)

run: solver
	mpirun -n 1 -host localhost ./solver

clean:
	rm -rf solver ../bin/Key.o

runParallel: solver
	mpirun -n 9 -host localhost ./solver
