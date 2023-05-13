#include "../ft_printf.h"

int ft_print_putnbr(int nb){
  int bit = 0;
  long int i = nb;

  if (i == -2147483648)
	{
		ft_print_putchr('-');
		ft_print_putchr('2');
		i = 147483648;
	}
	if (i < 0)
	{
		i = -i;
		ft_print_putchr('-');
	}
	if (i > 9)
	{
		ft_print_putnbr(i / 10);
		ft_print_putnbr(i % 10);
	}
	if (i <= 9)
	{
		ft_print_putchr(i + '0');
	}
  return bit;
}
