COMPILER=g++
OUTFILE=-o
OBJ=-c

main: main.o complex.o
	$(COMPILER) main.o complex.o $(OUTFILE) main
main.o: main.cpp
	$(COMPILER) main.cpp $(OBJ) $(OUTFILE) main.o
complex.o: complex.cpp complex.h
	$(COMPILER) complex.cpp $(OBJ) $(OUTFILE) complex.o 
clean: 
	rm *.o main
