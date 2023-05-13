#include "../ft_printf.h"

int ft_p_controller(long int p, int flags, int *width) {
  int result;
  char *string;
  int len ;

  result = 0;
  string = ft_hex(p, 32);
  len = ft_strlen_printf(string);
  if (flags & FLAG4) {
    if ((flags & FLAG6) || (flags & FLAG7)) {
      // result += ft_sharp_flag(32);
      result += ft_neg_controller(string, width[0], len) + ft_sharp_flag(32);
      return result;
    }
  } else if ((flags & FLAG6) || (flags & FLAG7)) {
    result += ft_width_flag(width[0] - 2, len);
  }
  result += ft_sharp_flag(32);
  write(1, string, len);
  free(string);
  return result + len;
}
