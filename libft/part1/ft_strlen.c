#include "../libft.h"

unsigned int	ft_strlen(char *str)
{
	const char *ptr;

	ptr = str;
	while (*ptr)
	{
		ptr++;
	}
	return (unsigned int)(ptr - str);
}