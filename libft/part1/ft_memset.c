#include "../libft.h"

void	*ft_memset(void *block, int value, size_t leng)
{
	size_t	i;
	unsigned char	*ptr;

	ptr = block;
	i = 0;
	while (i < leng)
		*(ptr + i++) = value;
	return (block);
}