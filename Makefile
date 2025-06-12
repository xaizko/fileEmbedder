flags=-O2 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean fileEmbedder

fileEmbedder: fileEmbedder.o
	cc $(flags) $^ -o $@ $(ldflags)

fileEmbedder.o: fileEmbedder.c fileEmbedder.h
	cc $(flags) -c $<

clean:
	rm -f *.o fileEmbedder