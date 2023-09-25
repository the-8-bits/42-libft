#include "../libft.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	
	sign = 1; // Initialize sign to positive
	result = 0;

	// Skip leading whitespace characters
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;

	// Handle the sign of the number
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1; // Negative sign
		str++;
	}

	// Convert the digits to an integer
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}