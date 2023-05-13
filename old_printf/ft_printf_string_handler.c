#include "../ft_printf.h"

int ft_s_handler (char *str, int flags, int *width) {
  int result = 0;
  char *string;
  int len = 0;

  string = ft_strdup(str);
  if ((flags & FLAG8) && ((flags & FLAG9) || (flags & FLAG10))) {
    len = width[1];
  } else {
    len = ft_strlen(string);
  }
  if (flags & FLAG4) {
    if ((flags & FLAG7) || (flags & FLAG6)) {
      result += ft_negspace_flag(width[0], string, len);
    } else {
      write(1, string, len);
    }
  } else if ((flags & FLAG7) || (flags & FLAG6)) {
    result += ft_width_flag(width[0], len);
    write(1, string, len);
  } else {
    write(1, string, len);
  }
  free(string);
  result += len;
  return result;
}
