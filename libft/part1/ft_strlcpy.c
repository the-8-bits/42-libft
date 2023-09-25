#include "../libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	if (size == 0)
		return ft_strlen(src);

	char *d = dest;
	const char *s = src;
	
	while (*s && (size - 1) > 0)
	{
		*d++ = *s++;
		size--;
	}

	*d = '\0';

	// Calculate the length of the source string
	return ft_strlen(src);
}