queens: src/queens.c src/board.c src/board.h
	gcc src/queens.c src/board.c -o bin/queens -std=gnu89 -pedantic -Wall -Werror -O4 -Iinclude
