#include "../ft_printf.h"

unsigned int ft_unsigned_intlen(unsigned int n) {
  unsigned int i = 0;

  while (n > 0){
    n = n / 10;
    i++;
  }
  return i;
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	int		i;
	unsigned int		len;

	i = 0;
	len = ft_unsigned_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
  if (!str)
    return NULL;
	while (n > 0)
	{
		str[len - i++ - 1] = '0' + (n % 10);
		n /= 10;
	}
	str[len] = '\0';
	return (str);
}
