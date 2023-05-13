#include "../ft_printf.h"

int ft_u_width(int *width, int len, int flags) {
  int result;

  result = 0;
  if(flags & FLAG2) {
    write(1, "+", 1);
    width[0] -= 1;
  } else if (flags & FLAG3) {
    write(1, " ", 1);
    width[0] -= 1;
  }
  result += ft_width_flag(width[0], len);
  return result;
}

int ft_u_controller(unsigned int num, int flags, int *width) {
  int result = 0;
  char *string;
  int len = 0;

  string = ft_unsigned_itoa(num);
  len = ft_set_length(width[1], string, flags);
  if (flags & FLAG5) {
    result += ft_zero_flag(width[0], len, flags);
  } else if (flags & FLAG4) {
    if ((flags & FLAG6) || (flags & FLAG7)) {
      return result += ft_neg_controller(string, width[0], len);
    }
  } else if ((flags & FLAG7) || (flags & FLAG6)) {
    result += ft_u_width(width, len, flags);
  }
  write(1, string, len);
  free(string);
  return result + len;
}
