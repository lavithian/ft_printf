#include "../ft_printf.h"

int ft_u_handler(unsigned int hex, int flags, int *width) {
  int result = 0;
  char *string;
  int len = 0;

  string = ft_unsigned_itoa(hex);
  if ((flags & FLAG8) && ((flags & FLAG9) || (flags & FLAG10))) {
    len = width[1];
  } else {
    len = ft_strlen(string);
  }
  if (flags & FLAG5) {
    result = ft_zero_flag(width[0], len, 1);
    write(1, string, len);
  } else if (flags & FLAG4) {
    result += ft_negspace_flag(width[0], string, len);
  } else if ((flags & FLAG7) || (flags & FLAG6)) {
    if(flags & FLAG2) {
      write(1, "+", 1);
      width[0] -= 1;
    } else if (flags & FLAG3) {
      write(1, " ", 1);
      width[0] -= 1;
    }
    result += ft_width_flag(width[0], len);
    write(1, string, len);
  } else {
    write(1, string, len);
  }
  free(string);
  return result + len;
}
