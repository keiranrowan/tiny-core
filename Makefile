CC=gcc
CFLAGS=-I.

all: cat false true wc

cat: cat.c
	gcc cat.c -o bin/cat

false: false.c
	gcc false.c -o bin/false

true: true.c
	gcc true.c -o bin/true

wc: wc.c
	gcc wc.c -o bin/wc

clean:
	rm bin/*

.PHONY: all clean
