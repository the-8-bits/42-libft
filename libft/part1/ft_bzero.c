#include "../libft.h"

void	ft_bzero(void *block, size_t n)
{
	size_t	i;
	char	*ptr;

	if (!n)
		return ;
	ptr = block;
	i = 0;
	while (i < n)
		*(ptr + i++) = 0;
}