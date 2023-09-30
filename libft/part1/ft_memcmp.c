#include "../libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	// Convert the pointers to unsigned char pointers
	const unsigned char *p1 = (const unsigned char *)s1;
	const unsigned char *p2 = (const unsigned char *)s2;

	while (n-- > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2); // Return the difference between the differing bytes
		p1++;
		p2++;
	}

	return (0); // Memory blocks are equal up to the specified number of bytes
}