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
  print_board(board);

  if (menuOption == 1)
  {
    while (1)
    {
      insert_player_move(board);

      if (has_player_won(board) || is_board_full(board))
      {
        break;
      }
    }
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

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
  printf("+-----------+\n");

  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (j == 2)
      {
        printf("| %c |\n", board[i][j]);
        printf("+-----------+\n");
      }
      else
      {
        printf("| %c ", board[i][j]);
      }
    }
  }
}

bool is_board_full(char board[BOARD_SIZE][BOARD_SIZE])
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == EMPTY)
      {
        return false;
      }
    }
  }

  return true;
}

void insert_player_move(char board[BOARD_SIZE][BOARD_SIZE])
{
  int rowPosition;
  int columnPosition;
  int result;
  char character;

  while (1)
  {
    while (1)
    {
      printf("[INFO] Please enter a row position (1-%d): ", BOARD_SIZE);

      result = scanf("%d", &rowPosition);

      while ((character = getchar()) != '\n' && character != EOF);

      if (result != 1 || rowPosition < 1 || rowPosition > BOARD_SIZE)
      {
        printf("[ERROR] Invalid row position. Please enter a valid position (1-%d).\n", BOARD_SIZE);
        continue;
      }
      else
      {
        break;
      }
    }

    while (1)
    {
      printf("[INFO] Please enter a column position (1-%d): ", BOARD_SIZE);

      result = scanf("%d", &columnPosition);

      while ((character = getchar()) != '\n' && character != EOF);

      if (result != 1 || columnPosition < 1 || columnPosition > BOARD_SIZE)
      {
        printf("[ERROR] Invalid column position. Please enter a valid position (1-%d).\n", BOARD_SIZE);
        continue;
      }
      else
      {
        break;
      }
    }

    rowPosition -= 1;
    columnPosition -= 1;

    if (board[rowPosition][columnPosition] == PLAYER || board[rowPosition][columnPosition] == AI)
    {
      printf("[ERROR] Position (%d, %d) is already occupied. Please choose another.\n", rowPosition + 1, columnPosition + 1);
    }
    else
    {
      board[rowPosition][columnPosition] = PLAYER;

      break;
    }
  }

  print_board(board);
}

bool has_player_won(char board[BOARD_SIZE][BOARD_SIZE])
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    if (
      (board[i][0] == PLAYER && board[i][1] == PLAYER && board[i][2] == PLAYER) ||
      (board[0][i] == PLAYER && board[1][i] == PLAYER && board[2][i] == PLAYER))
    {
      printf("[INFO] You won!\n");

      return true;
    }
  }

  if (
    (board[0][0] == PLAYER && board[1][1] == PLAYER && board[2][2] == PLAYER) ||
    (board[0][2] == PLAYER && board[1][1] == PLAYER && board[2][0] == PLAYER))
  {
    printf("[INFO] You won!\n");

    return true;
  }

  return false;
}