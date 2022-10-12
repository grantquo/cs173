main: main.o Rational.o
	g++ main.o Rational.o -o main

main.o: main.cpp Rational.h
	g++ -c main.cpp

Rational.o: Rational.cpp Rational.h
	g++ -c Rational.cpp
