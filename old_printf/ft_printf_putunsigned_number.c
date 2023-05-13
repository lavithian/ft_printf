#include "../ft_printf.h"

int ft_putunsignbr(unsigned int nb) {
	if (nb > 9)
	{
		ft_print_putnbr(nb / 10);
		ft_print_putnbr(nb % 10);
	}
	if (nb <= 9)
	{
		ft_print_putchr(nb + '0');
	}
  return 1;
}
