#include "../ft_printf.h"

int ft_zero_flag(int width, int len, int flags) {
  int result;

  result = width = width - len;
  if (flags & FLAG12) {
    width -= 1;
  }
  while (width > 0) {
    write(1, "0", 1);
    width--;
  }
  return result;
}
