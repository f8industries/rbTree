CFLAGS=-Wall -g

all: main.o tree.o
	cc -o rbTree main.o tree.o

main.o: main.c
	cc -c main.c -I ./

tree.o: tree.c
	cc -c tree.c -I ./

clean:
	rm -f rbTree
	rm -rf *.o
	#rm -rf *.dSYM
