#include "../include/game.h"

int main(void)
{
  print_menu();
  handle_menu(get_menu_option());

  return 0;
}
