#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t total;
	void *buffer;

	total = nmemb * size; // Calculate the total size needed for the allocated memory
	buffer = malloc(total); // Allocate memory for the array
	if (!buffer)
		return (NULL); // Return NULL if memory allocation fails

	ft_bzero(buffer, total); // Initialize all bytes in the allocated memory to zero
	return (buffer); // Return a pointer to the allocated and zero-initialized memory
}