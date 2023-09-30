#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr = s; // Convert the pointer to an unsigned char pointer
	unsigned char unchar = (unsigned char)c; // Convert the character to an unsigned char

	while (n-- > 0)
	{
		if (*ptr == unchar)
			return (void *)ptr; // Character found, return pointer to it
		ptr++;
	}

	return (NULL); // Character not found
}
