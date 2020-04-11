all: thread_1

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

thread_1: thread_1.o
	$(CC) $(LDFLAGS) -o $@ $^

thread_1.o: thread_1.cc
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm thread_1.o thread_1 core