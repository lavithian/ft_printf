#include "../ft_printf.h"

int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
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
