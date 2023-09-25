#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_len;
	
	s_len = ft_strlen(s);

	if (start >= s_len)
		return (ft_strdup("")); // Return an empty string if start is beyond the end of s
	
	len = (len > s_len - start) ? s_len - start : len; // Adjust len if it exceeds the available characters in s
	
	char *str = (char *)malloc(len + 1); // Allocate memory for the substring plus a null terminator
	
	if (!str)
		return (NULL); // Return NULL if memory allocation fails
	
	ft_memcpy(str, s + start, len); // Copy the substring from s to str
	str[len] = '\0'; // Null-terminate the substring
	
	return (str); // Return a pointer to the allocated substring
}