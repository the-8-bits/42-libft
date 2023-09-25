#include "../libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n) // recebe três argumentos: um ponteiro para uma string de destino (dest), um ponteiro para uma string de origem (src) e um inteiro sem sinal que representa o número máximo de caracteres a serem copiados da string de origem para a string de destino (n). A função retorna um ponteiro para a string de destino.
{
	char *dest_start = dest; // Store the start position of 'dest'

	// Copy characters from 'src' to 'dest' while 'n' is greater than zero and the current character in 'src' is not null
	while (n > 0 && *src != '\0') {
		*dest++ = *src++; // Copy character and increment both source and destination pointers
		n--;
	}

	// Fill the remaining characters in 'dest' with null characters if 'n' is still greater than zero
	while (n > 0) {
		*dest++ = '\0'; // Fill with null character and increment destination pointer
		n--;
	}

	return (dest_start); // Return a pointer to the beginning of 'dest'
}