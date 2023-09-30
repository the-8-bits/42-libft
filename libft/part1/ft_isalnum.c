#include "../libft.h"

int	ft_isalnum(char *str)
{
	while (*str)
	{
		if (!(((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) ||
			  (*str >= '0' && *str <= '9')))
			return (0);
		str++;
	}
	return (1);
}