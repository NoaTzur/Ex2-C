CC = gcc
FLAGS=-Wall


all: main
	
main: main.o libmyBank.a
	$(CC) $(FLAGS) main.o -L. -lmyBank -o main
	
main.o: main.c
	$(CC) $(FLAGS) -c main.c -o main.o
	
myBank: libmyBank.a

libmyBank.a: myBank.o banksStatus.o myBank.h
	ar -rcs libmyBank.a myBank.o banksStatus.o

myBank.o: myBank.c
	$(CC) $(FLAGS) -c -fPIC myBank.c
	
banksStatus.o: banksStatus.c
	$(CC) $(FLAGS) -c -fPIC banksStatus.c

	
.PHONY: clean all 


clean:
	rm -f main *.o *.a
	