#pragma once

#define BOARD_SIZE 3

void print_menu();
int get_menu_option();
void handle_menu(int menuOption);
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
