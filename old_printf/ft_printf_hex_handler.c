#include "../ft_printf.h"

int ft_hex_handler(unsigned long hex, int flags, int *width, int alcase) {
  int result = 0;
  char *string;
  int len = 0;

  string = ft_hex(hex, alcase);
  if ((flags & FLAG8) && ((flags & FLAG9) || (flags & FLAG10))) {
    len = width[1];
  } else {
    len = ft_strlen(string);
  }
  // BUGSTR(string);
  if (flags & FLAG1) {
    // result += ft_hex_flag(alcase);
    width[0] -=2;
  }
  if (flags & FLAG5) {
    if (flags & FLAG1) {
      result += ft_hex_flag(alcase);
    }
    result = ft_zero_flag(width[0], len, 1);
    write(1, string, len);
  } else if (flags & FLAG4) {
    if (flags & FLAG1) {
      result += ft_hex_flag(alcase);
    }
    result += ft_negspace_flag(width[0], string, len);
  } else if ((flags & FLAG7) || (flags & FLAG6)) {
    result += ft_width_flag(width[0], len);
    if (flags & FLAG1) {
      result += ft_hex_flag(alcase);
    }
    write(1, string, len);
  } else {
    if (flags & FLAG1) {
      result += ft_hex_flag(alcase);
    };
    write(1, string, len);
  }
  free(string);
  return result + len;
}
