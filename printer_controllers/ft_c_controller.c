#include "../ft_printf.h"

int ft_c_controller (int c, int flags, int *width) {
  int result;

  result = 0;
  if (flags & FLAG4) {
    if ((flags & FLAG6) || (flags & FLAG7)) {
      result += ft_print_char(c);
      result += ft_width_flag(width[0], 1);
      return result;
    }
  } else if ((flags & FLAG6) || (flags & FLAG7)) {
    result += ft_width_flag(width[0], 1);
  }
  result += ft_print_char(c);
  return result + 1;
}
