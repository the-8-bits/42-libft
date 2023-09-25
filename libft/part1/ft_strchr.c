#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s); // Found the character, return its pointer
		s++; // Move to the next character in the string
	}
	
	// Check for the null terminator (end of string)
	if ((char)c == '\0')
		return ((char *)s); // Character is the null terminator
	
	return (NULL); // Character not found in the string
}