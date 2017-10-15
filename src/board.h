#ifndef BOARD_H
#define BOARD_H


/*
 * can be >= 4 since 5x5 is the smallest on which 5 queens can be placed
 */
#define N (8)

#define ROWS (N)
#define COLS (N)
#define QUEENS (N)

#define DIAGS ((N + N - 1) * 2)

struct board {
	bool board[ROWS][COLS];
	bool row_has[ROWS];
	bool col_has[COLS];
	bool diag_has[DIAGS];
	int placed;
};

struct diag_index_pair {
	int index1, index2;
};

void empty_board(struct board *board);

void print_board(const struct board *board);

void coord_to_diag_index_pair(int i, int j, struct diag_index_pair *dp);

#endif
