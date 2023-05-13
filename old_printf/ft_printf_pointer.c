#include "../ft_printf.h"

int ft_pointeradd(long p) {
  int bit = 0;

  write(1, "0x", 2);
  ft_hex(p, 32);

  return bit;
}
