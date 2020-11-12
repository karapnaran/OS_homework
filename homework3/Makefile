COMPILER=gcc

all: silent_shell
silent_shell: silent_shell.o 
	$(COMPILER) silent_shell.o -o silent_shell
copyfile.o: silent_shell.cpp
	$(COMPILER) -c silent_shell -o silent_shell.o
clean:
	rm *.o silent_shell
