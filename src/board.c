#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "board.h"

void empty_board(struct board *board)
{
	int i;
	for (i=0; i<ROWS; i++)
		memset(board->board[i], 0, sizeof(board->board[i][0]) * COLS);
	memset(board->row_has, 0, sizeof(board->row_has[0]) * ROWS);
	memset(board->col_has, 0, sizeof(board->col_has[0]) * COLS);
	memset(board->diag_has, 0, sizeof(board->diag_has[0]) * DIAGS);
	board->placed = 0;
}

void print_board(const struct board *board)
{
	int i, j;
	for (i=0; i<ROWS; i++) {
		for (j=0; j<COLS; j++) {
			if (board->board[i][j])
				putchar('Q');
			else
				putchar('K');
		}
		putchar('\n');
	}
}

void coord_to_diag_index_pair(int i, int j, struct diag_index_pair *dp)
{
	int x, y;
	for (x=i,y=j; x>0 && y>0; x--, y--) ;

	dp->index1 = x == 0 ? y : ROWS + x - 1;

	for (x=i, y=j; x > 0 && y < COLS-1; x--, y++) ;

	dp->index2 = x == 0 ? DIAGS / 2 + y : DIAGS / 2 + COLS + x - 1;
}
