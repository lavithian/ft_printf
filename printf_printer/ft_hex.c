#include "../ft_printf.h"

char *ft_hex(unsigned long dec, int alcase) {
  char *p;
  char hex[12];
  ft_memset(hex, 0, sizeof(hex));
  int i = 11;

  while (dec > 0) {
    int remainder = dec %16;
    if (remainder < 10) {
      hex[i] = remainder + '0';
    } else if (remainder < 16) {
      hex[i] = 'A' + alcase + remainder % 10;
    }
    i--;
    dec /= 16;
  }
  p = ft_strdup(hex + i + 1);
  // free(hex);
  return p;
}
