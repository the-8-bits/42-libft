#include "../libft.h"

void ft_putnbr_fd(int n, int fd)
{
	char str[13];  // Sufficient space for an int and possible sign
	int is_neg = (n < 0);
	int length = 0;

	ft_bzero(str, 13); // Initialize the string buffer with zeros

	if (n == 0)
	{
		str[0] = '0';
		length++;
	}
	else
	{
		// Ensure there's enough space in the buffer and handle integer conversion
		while (n != 0 && length < 13) // Prevent buffer overflow
		{
			str[length++] = '0' + ft_abs(n % 10);
			n = n / 10;
		}

		// If the buffer is full and n is not zero, indicate buffer overflow
		if (n != 0)
		{
			write(fd, "Buffer Overflow", 15);
			return;
		}
	}

	if (is_neg)
	{
		if (length < 13)
			str[length++] = '-';
		else
		{
			write(fd, "Buffer Overflow", 15);
			return;
		}
	}

	while (length > 0)
	{
		write(fd, &str[--length], 1); // Write each character of the string
	}
}
