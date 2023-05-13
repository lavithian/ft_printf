#include "../ft_printf.h"


int ft_strlen(const char *str) {
  int i;

  i = 0;
  while (str[i]) {
    i++;
  }
  return i;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
  if (!dst && !src)
		return (NULL);
	while (n-- > 0)
	{
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	return (dst);
}

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(str);
	if (len + 1 < len)
	{
		return (NULL);
	}
	new_str = malloc((len + 1) * (sizeof(char)));
  if (!new_str)
    return (NULL);
	if (!str)
	{
		*new_str = '\0';
	}
	else
	{
		ft_memcpy(new_str, str, (len + 1) * sizeof(char));
	}
	return (new_str);
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
  MEMCHECK(str);
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
    return NULL
	while (n > 0)
	{
		str[len - i++ - 1] = '0' + (n % 10);
		n /= 10;
	}
	str[len] = '\0';
	return (str);
}

void	*ft_memset(void *str, int c, size_t len)
{
	while (len-- > 0)
	{
		((unsigned char *)str)[len] = c;
	}
	return (str);
}

int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
		{
			sign = -1;
		}
		else
		{
			sign = 1;
		}
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str++ - '0');
	}
	return (result * sign);
}

void	ft_intzero(int *s, size_t n)
{
  while (n-- > 0)
  {
    ((unsigned int *)s)[n] = 0;
  }
}
