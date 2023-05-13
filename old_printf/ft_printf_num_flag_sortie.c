#include "../ft_printf.h"

int ft_num_sortie (int flags) {
  if (flags & FLAG2) {
    flags = flags - FLAG2;
  }
  if (flags & FLAG3) {
    flags = flags - FLAG3;
  }
  return flags;
}
