output: main.o errors.o student.o hashtable.o search.o
	gcc main.o errors.o student.o hashtable.o search.o -o output
main.o: main.c
	gcc -c main.c
errors.o: errors.c errors.h
	gcc -c errors.c
student.o: student.c student.h
	gcc -c student.c
hashtable.o: hashtable.c hashtable.h
	gcc -c hashtable.c
search.o: search.c search.h
	gcc -c search.c
clean:
	rm *.o output