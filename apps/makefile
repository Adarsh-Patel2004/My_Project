CC=gcc
CFLAGS=-Wall -I../trie -I../util
LDFLAGS=-L../trie -L../util
LDLIBS=-ltrie -lutil

all: maxchain subwords

maxchain: maxchain.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

subwords: subwords.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o maxchain subwords
