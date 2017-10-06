CC=g++
CXXFLAGS=-Wall -std=c++11 -g
#LIBS=-lpmi
INCLUDES=-I../include

all: main Logger.o GA.o Individual.o Population.o Evaluator.o config.o

Logger.o: ../include/Logger.h ../src/Logger.cpp
	$(CC) $(CXXFLAGS) -c ../src/Logger.cpp -o Logger.o $(INCLUDES)

GA.o: ../include/GA.h ../src/GA.cpp ../include/config.h
	$(CC) $(CXXFLAGS) -c ../src/GA.cpp -o GA.o  $(INCLUDES)

Individual.o: ../include/Individual.h ../src/Individual.cpp ../include/config.h
	$(CC) $(CXXFLAGS) -c ../src/Individual.cpp -o Individual.o  $(INCLUDES)

Population.o: ../include/Population.h ../src/Population.cpp ../include/config.h
	$(CC) $(CXXFLAGS) -c ../src/Population.cpp -o Population.o  $(INCLUDES)

Evaluator.o: ../include/Evaluator.h ../src/Evaluator.cpp ../include/config.h
	$(CC) $(CXXFLAGS) -c ../src/Evaluator.cpp -o Evaluator.o $(INCLUDES)

config.o: ../include/config.h ../src/config.cpp
	$(CC) $(CXXFLAGS) -c ../src/config.cpp -o config.o $(INCLUDES)

main: ../src/main.cpp Logger.o GA.o Individual.o Population.o Evaluator.o config.o
	$(CC) $(CXXFLAGS) -o main ../src/main.cpp Logger.o Individual.o Population.o Evaluator.o GA.o config.o $(INCLUDES) $(LIBS)

clean:
	rm -rf *.o main*

run: main
	./main