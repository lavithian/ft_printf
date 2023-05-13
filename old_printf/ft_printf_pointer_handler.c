#include "../ft_printf.h"

int ft_p_handler(long int p, int flags, int *width) {
  int result = 0;
  char *string;
  int len = 0;

  string = ft_hex(p, 32);
  len = ft_strlen(string);

  if (flags & FLAG4) {
    if ((flags & FLAG7) || (flags & FLAG6)) {
      result += ft_negspace_hex_flag(width[0], string, len);
    } else {
      result += ft_hex_flag(32);
      write(1, string, len);
    }
  } else if ((flags & FLAG7) || (flags & FLAG6)) {
    result += ft_width_flag(width[0] - 2, len);
    result += ft_hex_flag(32);
    write(1, string, len);
  } else {
    result = ft_hex_flag(32);
    write(1, string, len);
  }
  free(string);
  return result + len;
}
