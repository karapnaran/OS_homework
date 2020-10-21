all: copyfile

copyfile: copyfile.o 
	gcc copyfile.o -o copyfile

copyfile.o: copyfile.c
	gcc -c copyfile.c -o copyfile.o

clean:
	rm *.o copyfile