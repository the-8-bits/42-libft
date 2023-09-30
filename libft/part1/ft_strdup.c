#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1; // Calculate the size needed for the duplicate string, including the null terminator
	dup = (char *)malloc(size); // Allocate memory for the duplicate string
	if (!dup)
		return (NULL); // Return NULL if memory allocation fails

	ft_memcpy(dup, s, size); // Copy the contents of the original string into the duplicate string
	return (dup); // Return a pointer to the duplicate string
}