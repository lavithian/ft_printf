#include "../ft_printf.h"

void	ft_initzero(int *s, size_t n)
{
  while (n-- > 0)
  {
    ((unsigned int *)s)[n] = 0;
  }
}
