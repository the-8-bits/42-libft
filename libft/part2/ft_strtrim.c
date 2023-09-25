#include "../libft.h"

static int	ft_char_in_set(char c, const char *set)
{
	size_t	counter;

	counter = 0;
	while (set[counter])
	{
		if (set[counter] == c)
			return (1);
		counter++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	counter;
	size_t	start;
	size_t	end;
	size_t	trimmed_len;
	
	if (!s1 || !set)
		return (NULL); // Return NULL if either s1 or set is NULL

	start = 0;
	end = strlen(s1);

	// Find the start position by skipping characters in set from the beginning of s1
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;

	// Find the end position by skipping characters in set from the end of s1
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;

	// Calculate the length of the trimmed string
	trimmed_len = end - start;

	// Allocate memory for the trimmed string plus a null terminator
	char *str = (char *)malloc(trimmed_len + 1);

	if (!str)
		return (NULL); // Return NULL if memory allocation fails

	// Copy the trimmed characters from s1 to str
	counter = 0;
	while (start < end)
		str[counter++] = s1[start++];

	str[counter] = '\0'; // Null-terminate the trimmed string
	return (str); // Return a pointer to the trimmed string
}