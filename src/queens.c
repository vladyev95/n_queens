#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "board.h"

static int total;
void queens(struct board *board, int last)
{
	int i, r, c;
	struct diag_index_pair pair;
	if (board->placed == QUEENS) {
		/*print_board(board);
		putchar('\n');
		*/
		total++;
		return;
	}
	
	/*
	 * move on the next row
	 */
	for (i=last == -1 ? 0 : last / COLS * COLS + COLS; i<ROWS*COLS; i++) {
		r = i / COLS;
		c = i % COLS;
		coord_to_diag_index_pair(r, c, &pair);
		if (board->row_has[r] || board->col_has[c] ||
			board->diag_has[pair.index1] ||
			board->diag_has[pair.index2])
			continue;
		board->board[r][c] = true;
		board->row_has[r] = true;
		board->col_has[c] = true;
		board->diag_has[pair.index1] = true;
		board->diag_has[pair.index2] = true;

		board->placed++;
		queens(board, i);
		board->placed--;

		board->board[r][c] = false;
		board->row_has[r] = false;
		board->col_has[c] = false;
		board->diag_has[pair.index1] = false;
		board->diag_has[pair.index2] = false;
	}
}


int main(void)
{
	struct board board;
	empty_board(&board);
	queens(&board, -1);
	printf("total: %d\n", total);
	return EXIT_SUCCESS;
}
