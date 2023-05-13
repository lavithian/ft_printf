#include "../ft_printf.h"

int ft_set_length(int width, char *string, int flags) {
  int len = 0;

  if ((flags & FLAG8) && ((flags & FLAG9) || (flags & FLAG10))) {
    return len = width;
  } else {
    return len = ft_strlen_printf(string);
  }
}
