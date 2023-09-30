#include "../libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
		{
			write(fd, s, 1); // Write one character at a time
			s++;
		}

		char nl = '\n'; // Newline character

		write(fd, &nl, 1); // Write the newline character
	}
}