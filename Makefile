CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o Particle.o 
	$(CC) main.o Particle.o -o main $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) -o $@ $< -std=c++14

Particle.o: Particle.cpp
	$(CC) $(CFLAGS) -o $@ $< -std=c++14

clean:
	rm main *.o