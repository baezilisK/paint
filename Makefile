CC = gcc
LINK = -lGL -lGLU -lglut
NOWARN = -Wno-parentheses -Wno-sign-compare -Wno-unused-result
CFLAGS = -std=c89 -O4 -Wall -Werror -Wextra -pedantic $(NOWARN) $(LINK)
BIN = main

all: paint

clean:
	rm -f $(BIN)

paint: paint.c
	$(CC) $(CFLAGS) $(LINK) $< -o $(BIN)
