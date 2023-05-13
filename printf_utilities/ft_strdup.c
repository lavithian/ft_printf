#include "../ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	pika;

	pika = 0;
	while (str[pika])
	{
		pika++;
	}
	return (pika);
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
