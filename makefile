shell: shell.o history.o
	gcc -o shell shell.o history.o

shell.o: shell.c history.h
	gcc -c shell.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm -f *.o shell