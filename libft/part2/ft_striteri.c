#include "../libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (s != NULL && f != NULL)
	{
		unsigned int index = 0;

		while (*s)
		{
			(*f)(index, s); // Call the function 'f' with the current index and character
			s++; // Move to the next character
			index++; // Increment the index
		}
	}
}