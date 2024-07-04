CC = g++
CFLAGS = -Wall -std=c++17
LIBS = -lgdi32 -lopengl32 -lglu32

all: simple_example

simple_example: example.cpp raylib_mini.hpp
	$(CC) $(CFLAGS) example.cpp -o simple_example $(LIBS)

clean:
	rm -f simple_example