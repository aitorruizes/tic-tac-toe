#pragma once

#include <stdbool.h>

#define BOARD_SIZE 3
#define PLAYER 'X'
#define AI 'O'
#define EMPTY '-'

void print_menu();
int get_menu_option();
void handle_menu(int menuOption);
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
bool is_board_full(char board[BOARD_SIZE][BOARD_SIZE]);
void insert_player_move(char board[BOARD_SIZE][BOARD_SIZE]);
bool check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player);