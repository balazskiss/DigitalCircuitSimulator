CC=g++
CFLAGS=-c -Wall
OBJS = main.o Circuit.o CLI.o Component.o ComponentList.o NAND.o OR.o

all: dcs


$(OBJS):
	$(CC) $(CFLAGS) src/*.cpp

dcs: $(OBJS)
	$(CC) $(OBJS) -o dcs
	rm *.o
