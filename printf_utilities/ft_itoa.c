#include "../ft_printf.h"

int ft_intlen(int n) {
  int i = 0;

  if (n < 0){
    i++;
    n = -n;
  }
  while (n > 0){
    n = n / 10;
    i++;
  }
  return i;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	i = 0;
	len = ft_intlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc((len + 1) * sizeof(char));
  if (!str)
    return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len - i++ - 1] = '0' + (n % 10);
		n /= 10;
	}
	str[len] = '\0';
	return (str);
}
