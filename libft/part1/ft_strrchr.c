#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last_occurrence;

	*last_occurrence = NULL; // Initialize a pointer to track the last occurrence
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = s; // Update the pointer when a match is found
		s++;
	}

	if ((char)c == '\0')
		return ((char *)s); // Return a pointer to the null terminator if c is '\0'

	return ((char *)last_occurrence); // Return a pointer to the last occurrence or NULL if not found
}
