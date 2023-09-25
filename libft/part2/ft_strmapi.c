#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t idx;
	char *str;

	if (!(str = ft_strdup(s))) // Duplicate the input string 's' using 'ft_strdup'
		return (NULL);

	idx = 0;
	while (str[idx])
	{
		str[idx] = (*f)(idx, str[idx]); // Apply the function 'f' to each character
		idx++;
	}
	return (str); // Return a pointer to the newly created string
}