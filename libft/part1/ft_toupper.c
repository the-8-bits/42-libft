#include "../libft.h"

char	*ft_toupper(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] >= 'a' &&  str[counter] <= 'z' )
			str[counter] -= 32; // Convert lowercase letter to uppercase
		counter++;
	}
	return (str);
}