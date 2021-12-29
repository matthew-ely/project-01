compile: Matrix.o p1.o
	g++ -Wall -pedantic-errors -o p1 Matrix.o p1.o

p1.cpp: p1.cpp Matrix.h
	g++ -Wall -pedantic-errors -c p1.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -Wall -pedantic-errors -c Matrix.cpp

run: compile
	./p1

clean:
	rm -f p1
	rm -f *.o
