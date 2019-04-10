CXX = clang++
CC = clang

main:	functions.o student.o
	clang++ -o main main.cpp functions.o student.o
test:	main
	./main

clean:
	rm -f *.o main