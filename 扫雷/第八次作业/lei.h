#ifndef _LEI_H__
#define _LEI_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE_COUNT 10
void game();
void meun();
void play_game();
void display(char board[ROWS][COLS], int rows, int cols);
int get_mine_count(char mine[ROWS][COLS], int x, int y);
void set_mine(char mine[ROWS][COLS], int rows, int cols);
int count_board(char board[ROWS][COLS], int rows, int cols);
int move_board(char board[ROWS][COLS], char mine[ROWS][COLS], int x, int y);
#endif