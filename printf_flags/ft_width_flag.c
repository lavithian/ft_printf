#include "../ft_printf.h"

int ft_width_flag(int width, int len) {
  int result;

  result = width = width - len;
  while (width > 0) {
    write(1, " ", 1);
    width--;
  }
  return result;
}
