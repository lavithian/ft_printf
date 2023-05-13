#include "../ft_printf.h"

int ft_neg_controller(char *string, int width, int len) {
  int result;

  result = 0;
  write(1, string, len);
  result += ft_width_flag(width, len);
  free(string);
  return result;
}
