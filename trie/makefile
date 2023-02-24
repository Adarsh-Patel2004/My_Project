CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

SOURCES = trie.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = libtrie.so

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)