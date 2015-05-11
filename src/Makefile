CC = g++
CFLAGS = -std=c++14 -ggdb

main: main.o Socket.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp Socket.hpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf *~ *.o
