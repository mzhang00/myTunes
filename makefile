all: main.o linked.o myTunes.o
	gcc -o test_myTunes main.o linked.o myTunes.o

main.o: main.c linked.h
	gcc -c main.c

linked.o: linked.c linked.h
	gcc -c linked.c

myTunes.o: myTunes.c myTunes.h linked.h
	gcc -c myTunes.c

run:
	./test_myTunes

clean:
	rm *.o
	rm test_myTunes
	rm *~