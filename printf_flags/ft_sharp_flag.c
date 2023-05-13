#include "../ft_printf.h"

int ft_sharp_flag(int alcase) {
  char x = 'X';
  x += alcase;
  write(1, "0", 1);
  write(1, &x, 1);
  return 2;
}
