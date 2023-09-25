#include "../libft.h"

char	*ft_tolower(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] >= 'A' &&  str[counter] <= 'Z' )
			str[counter] += 32; // Convert uppercase letter to lowercase
		counter++;
	}
	return (str);
}