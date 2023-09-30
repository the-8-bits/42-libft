#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t b_counter;
	size_t l_counter;

	if (!*little)
		return ((char *)big); // Return a pointer to the beginning of big if little is an empty string

	b_counter = 0;
	while (big[b_counter] && b_counter < len)
	{
		l_counter = 0;
		while (big[b_counter + l_counter] == little[l_counter] && b_counter + l_counter < len)
		{
			if (little[l_counter + 1] == '\0')
				return (char *)(big + b_counter); // Return a pointer to the first occurrence of little within big
			l_counter++;
		}
		b_counter++;
	}

	return (NULL); // little is not found in big within the specified length
}