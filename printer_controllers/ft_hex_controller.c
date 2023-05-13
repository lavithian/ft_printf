#include "../ft_printf.h"

int ft_hex_sharp (int flags, int *width, int alcase) {
  int result = 0;
  if (flags & FLAG1) {
    width[0] -=2;
    result += ft_sharp_flag(alcase);
  }
  return result;
}

int ft_hex_zero_flag(int width, int alcase, int len, int flags){
  int result = 0;
  if (flags & FLAG1) {
    width -=2;
    result += ft_sharp_flag(alcase);
  }
  result += ft_zero_flag(width, len, 1);
  return result;
}

int ft_hex_width(int flags, int width, int len, int alcase){
  int result = 0;
  if (flags & FLAG1) {
    width -=2;
  }
  result += ft_width_flag(width, len);
  if (flags & FLAG1) {
    result += ft_sharp_flag(alcase);
  }
  return result;
}

int ft_hex_controller(unsigned long hex, int flags, int *width, int alcase) {
  int result;
  char *string;
  int len;

  result = 0;
  string = ft_hex(hex, alcase);
  len = ft_set_length(width[1], string, flags);
  if (flags & FLAG5) {
    result += ft_hex_zero_flag(width[0], alcase, len, flags);
  } else if (flags & FLAG4) {
    result += ft_hex_sharp(flags, width, alcase);
    result += ft_neg_controller(string, width[0], len);
    return result;
  } else if ((flags & FLAG6) || (flags & FLAG7)) {
    result += ft_hex_width(flags, width[0], len, alcase);
  }
  result += ft_hex_sharp (flags, width, alcase);
  write(1, string, len);
  free(string);
  return result + len;
}
