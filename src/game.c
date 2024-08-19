#include "../include/game.h"
#include <stdio.h>

void print_menu()
{
  printf("+---------------------------------------+\n");
  printf("|                                       |\n");
  printf("|              TIC-TAC-TOE              |\n");
  printf("|                                       |\n");
  printf("+---------------------------------------+\n");
  printf("|                                       |\n");
  printf("|  [1] - Player against another player  |\n");
  printf("|  [2] - Player against AI              |\n");
  printf("|                                       |\n");
  printf("+---------------------------------------+\n");
}

int get_menu_option()
{
  int menuOption;
  int result;
  char character;

  while (1)
  {
    printf("[INFO] Enter a valid menu option (1-2): ");

    result = scanf("%d", &menuOption);

    if (result == 1 && menuOption >= 1 && menuOption <= 2)
    {
      while ((character = getchar()) != '\n' && character != EOF);

      break;
    }
    else
    {
      while ((character = getchar()) != '\n' && character != EOF);

      printf("[ERROR] Invalid input. Please enter a valid menu option (1-2).\n");
    }
  }

  return menuOption;
}

void handle_menu(int menuOption)
{
  char board[BOARD_SIZE][BOARD_SIZE];

  initialize_board(board);

  if (menuOption == 1)
  {
    printf("This is the first option\n");
  }
  else
  {
    printf("This is the second option");
  }
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE])
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      board[i][j] = '-';
    }
  }
}