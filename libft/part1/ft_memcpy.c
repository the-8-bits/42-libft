#include "../libft.h"

void	*ft_memcpy(void *target, const void *source, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*ptr2;

	ptr = target;
	ptr2 = (char *)source;
	i = -1;
	while (++i < n)
		*(ptr + i) = *(ptr2 + i);
	return (target);
}