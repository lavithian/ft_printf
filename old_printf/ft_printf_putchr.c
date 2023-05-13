#include "../ft_printf.h"

char *ft_print_putchr(char c) {
  char *p;

  p = malloc(sizeof(char) + 1);
  MEMCHECK(p);
  *p = c;
  p[1] = '\0';

  return p;
}
