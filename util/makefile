CC = gcc
CFLAGS = -Wall -fpic
LDFLAGS = -shared

SOURCES = dictload.c dictutils.c
OBJECTS = $(SOURCES:.c=.o)

TARGET = libwordutils.so

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I../trie -I. -ltrie

clean:
	rm -f $(OBJECTS) $(TARGET)
