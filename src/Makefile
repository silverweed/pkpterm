CC = g++
CFLAGS = -std=c++11 $(INCS) $(DEBUG)
DEBUG =
INCS = -I../termbox/build/include/
LDFLAGS = $(LIBS) -ltermbox
LIBS = -L../termbox/build/lib/

all: main

main: main.o Socket.o Term.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp Socket.hpp Term.hpp
	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

.PHONY: clean remake
clean:
	rm -rf *~ *.o
remake: clean all
