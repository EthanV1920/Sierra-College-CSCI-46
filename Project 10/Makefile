load: dictionary.o main.o
	clang dictionary.o main.o -o load

dictionary.o: dictionary.c
	clang -g -c dictionary.c
	
main.o: main.c
	clang -g -c main.c
	
clean:
	rm -f load *.o
	
check: load
	valgrind ./load words1.txt