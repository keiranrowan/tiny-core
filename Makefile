CC=gcc
CFLAGS=-I./inc
SRC=./src
BIN=./bin
MODULES= cat false hostname sleep true wc yes

all: $(MODULES)

$(MODULES):
	$(CC) $(SRC)/$@.c -o $(BIN)/$@ $(CFLAGS)

debug: CFLAGS += -g

debug: all

clean:
	rm bin/*

.PHONY: all clean
