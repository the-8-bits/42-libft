/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:48:29 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/04 15:45:53 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	bufferoverflow_exit(void)
{
	write(fd, "Buffer Overflow", 15);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int		length;
	char	str[13]; // Sufficient space for an int and possible sign

	length = 0;
	ft_bzero(str, 13); // Initialize the string buff with zeros
	if (n < 0)
	{
		if (length < 13)
			str[length++] = '-';
		else
			bufferoverflow_exit(void);
	}
	else
	{
		if (n == 0)
		{
			str[0] = '0';
			length++;
		}
		else
		{ // Ensure there's enough space in the buffer and handle int conversion
			while (n != 0 && length < 13) // Prevent buff overflower conversion
			{
				str[length++] = '0' + ft_abs(n % 10);
				n = n / 10;
			}
			if (n != 0) // If the buffer is full, indicate bufferoverflow
				bufferoverflow_exit(void);
		}
	}
	while (length > 0)
	{
		write(fd, &str[--length], 1); // Write each character of the string
	}
}
