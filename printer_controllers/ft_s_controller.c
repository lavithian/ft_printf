#include "../ft_printf.h"

int ft_s_controller (char *str, int flags, int *width)
{
  int result;
  char *string;
  int len;

  result = 0;
  string = ft_strdup(str);
  len = ft_set_length(width[1], string, flags);
  if (flags & FLAG4) {
    if ((flags & FLAG6) || (flags & FLAG7)) {
      return result += ft_neg_controller(string, width[0], len);
    }
  } else if ((flags & FLAG6) || (flags & FLAG7)) {
    result += ft_width_flag(width[0], len);
  }
  write(1, string, len);
  free(string);
  return result + len;
}
