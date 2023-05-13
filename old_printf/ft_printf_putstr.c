#include "../ft_printf.h"

int ft_print_putstr(char *str) {
  int len = ft_strlen(str);

  write(1, str, len);
  return len;
}
