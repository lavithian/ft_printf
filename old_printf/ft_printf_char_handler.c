#include "../ft_printf.h"

int ft_c_handler (int c, int flags, int *width) {
  int result = 0;
  char *string;
  string = ft_print_putchr(c);
  if (flags & FLAG4) {
    if ((flags & FLAG7) || (flags & FLAG6)) {
      result += ft_negspace_flag(width[0], string, 1);
    } else {
      write(1, string, 1);
    }
  } else if ((flags & FLAG7) || (flags & FLAG6)) {
    result += ft_width_flag(width[0], 1);
    write(1, string, 1);
  } else {
    write(1, string, 1);
  }
  free(string);
  return result + 1;

}
