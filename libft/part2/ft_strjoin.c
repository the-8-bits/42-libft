#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t len1;
	size_t len2;
	
	len1 = ft_strlen(s1); // Calculate the length of s1
	len2 = ft_strlen(s2); // Calculate the length of s2
	// Allocate memory for the result string, including space for the null terminator
	char *str = (char *)malloc(len1 + len2 + 1);
	
	if (!str)
		return (NULL); // Return NULL if memory allocation fails

	ft_strcat(str, s1); // Copy s1 into str
	ft_strcat(str, s2); // Append s2 to str

	return (str); // Return a pointer to the concatenated string
}