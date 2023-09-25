#include "../libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (n > 0 && s1[counter] != '\0' && s1[counter] == s2[counter])
	{
		counter++;
		n--;
	}

	if (n == 0 || (s1[counter] == '\0' && s2[counter] == '\0'))
		return (0);

	return (int)(s1[counter] - s2[counter]);
}