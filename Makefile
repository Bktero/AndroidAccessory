CC=gcc
CFLAGS=-W -Wall
LDFLAGS=-lusb-1.0
EXEC=AndroidAccessory


all: $(EXEC)

AndroidAccessory: main.o comAndroid.o
	$(CC) -o AndroidAccessory main.o comAndroid.o $(LDFLAGS)

main.o: main.c comAndroid.h
	$(CC) -o main.o -c main.c $(CFLAGS)

comAndroid.o: comAndroid.c
	$(CC) -o comAndroid.o -c comAndroid.c $(CFLAGS)

clean:
	rm ./*.o

clean_all : clean
	rm ./$(EXEC)
