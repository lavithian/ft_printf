#include "../ft_printf.h"

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
