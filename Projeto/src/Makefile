CFLAGS=-Wall -Wextra -pedantic -O2
LIBS=-lm -lcurses

jogo: player.c fov.c mapa.c main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm jogo *.o
