CC = g++
CFLAGS = -std=c++11 $(INCS) $(DEBUG) -static -Wall
DEBUG = -ggdb
INCS = -I../termbox/build/include/
LDFLAGS = $(LIBS) -ltermbox
LIBS = -L../termbox/build/lib/

all: main

main: main.o Socket.o Term.o Client.o Executor.o DefaultExecutor.o
	$(CC) $(CFLAGS) $^ -o ../$@ $(LDFLAGS)

Socket.o: Socket.cpp Socket.hpp
	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

Term.o: Term.cpp Term.hpp
	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

Executor.o: Executor.cpp Executor.hpp
	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

DefaultExecutor.o: DefaultExecutor.cpp DefaultExecutor.hpp Executor.hpp
	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

#%.o: %.cpp Socket.hpp Term.hpp Client.hpp Executor.hpp DefaultExecutor.hpp
#	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

.PHONY: clean remake
clean:
	rm -rf *~ *.o
remake: clean all
