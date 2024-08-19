#include "../include/game.h"
#include <stdio.h>
#include <limits.h>

void print_menu()
{
  printf("+---------------------------------+\n");
  printf("|                                 |\n");
  printf("|           TIC-TAC-TOE           |\n");
  printf("|                                 |\n");
  printf("+---------------------------------+\n");
  printf("|                                 |\n");
  printf("|      [1] - Play against AI      |\n");
  printf("|      [2] - Exit                 |\n");
  printf("|                                 |\n");
  printf("+---------------------------------+\n");
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

      if (check_winner(board, PLAYER))
      {
        printf("[INFO] You won!\n");

        break;
      }

      if (is_board_full(board))
      {
        printf("[INFO] The game is a draw.\n");

        break;
      }

      int rowPosition;
      int columnPosition;

      find_best_move(board, &rowPosition, &columnPosition);

      board[rowPosition][columnPosition] = AI;

      print_board(board);

      if (check_winner(board, AI))
      {
        printf("[INFO] You lose!\n");

        break;
      }

      if (is_board_full(board))
      {
        printf("[INFO] The game is a draw.\n");

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

bool check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    if (
      (board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
      (board[0][i] == player && board[1][i] == player && board[2][i] == player)
    )
    {
      return true;
    }
  }

  if (
    (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
    (board[0][2] == player && board[1][1] == player && board[2][0] == player)
  )
  {
    return true;
  }

  return false;
}

int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, int isMaximizing)
{
  char player = isMaximizing ? 'O' : 'X';
  char opponent = isMaximizing ? 'X' : 'O';

  if (check_winner(board, player))
  {
    return 10 - depth;
  }

  if (check_winner(board, opponent))
  {
    return depth - 10;
  }

  if (is_board_full(board))
  {
    return 0;
  }

  if (isMaximizing)
  {
    int bestScore = INT_MIN;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
      for (int j = 0; j < BOARD_SIZE; j++)
      {
        if (board[i][j] == EMPTY)
        {
          board[i][j] = 'O';

          int score = minimax(board, depth + 1, 0);

          board[i][j] = EMPTY;

          if (score > bestScore)
          {
            bestScore = score;
          }
        }
      }
    }

    return bestScore;
  }
  else
  {
    int bestScore = INT_MAX;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
      for (int j = 0; j < BOARD_SIZE; j++)
      {
        if (board[i][j] == EMPTY)
        {
          board[i][j] = 'X';

          int score = minimax(board, depth + 1, 1);

          board[i][j] = EMPTY;

          if (score < bestScore)
          {
            bestScore = score;
          }
        }
      }
    }

    return bestScore;
  }
}

void find_best_move(char board[BOARD_SIZE][BOARD_SIZE], int *bestMoveRow, int *bestMoveCol)
{
  int bestScore = INT_MIN;

  *bestMoveRow = -1;
  *bestMoveCol = -1;

  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == EMPTY)
      {
        board[i][j] = AI;

        int score = minimax(board, 0, 0);

        board[i][j] = EMPTY;

        if (score > bestScore)
        {
          bestScore = score;
          *bestMoveRow = i;
          *bestMoveCol = j;
        }
      }
    }
  }
}
