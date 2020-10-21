COMPILER=gcc

all: copyfile

copyfile: copyfile.o 
	$(COMPILER) copyfile.o -o copyfile

copyfile.o: copyfile.c
	$(COMPILER) -c copyfile.c -o copyfile.o

clean:
	rm *.o copyfile
