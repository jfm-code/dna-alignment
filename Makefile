CC = g++
CFLAGS = -std=c++17 -Wall -Werror -pedantic -g
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: EDistance EDistance.a test

EDistance: main.o EDistance.o
	$(CC) $(CFLAGS) -o EDistance main.o EDistance.o $(LIBS)

EDistance.a: EDistance.o
	ar rcs EDistance.a EDistance.o

EDistance.o: EDistance.cpp EDistance.hpp
	$(CC) $(CFLAGS) -c EDistance.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

lint: main.cpp
	cpplint main.cpp

test: EDistance.o
	$(CC) $(CFLAGS) -o test test.cpp EDistance.o $(LIBS)
	./test

clean: 
	rm *.o EDistance test