COMPILER=g++

main: main.o complex.o
	$(COMPILER) main.o complex.o -o main
main.o: main.cpp complex.cpp complex.h
	$(COMPILER) main.cpp -c -o main.o
complex.o: complex.cpp complex.h
	$(COMPILER) complex.cpp -c -o complex.o 
clean: 
	rm *.o main
