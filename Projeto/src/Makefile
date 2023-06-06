CFLAGS=-Wall -Wextra -pedantic -O2
LIBS=-lm -lcurses

jogo: mapa.c main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm jogo *.o
