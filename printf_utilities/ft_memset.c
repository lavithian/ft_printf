#include "../ft_printf.h"

void	*ft_memset(void *str, int c, size_t len)
{
	while (len-- > 0)
	{
		((unsigned char *)str)[len] = c;
	}
	return (str);
}
