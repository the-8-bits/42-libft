/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:07:34 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 16:50:35 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*dest_start;

	*dest_start = dest; // Store the start position of 'dest'
	/*Copy characters from 'src' to 'dest' while 'n' is greater than zero and
	 * the current character in 'src' is not null */
	while (n > 0 && *src != '\0')
	{
		// Copy character and increment both source and destination pointers
		*dest++ = *src++;
		n--;
	}
	/* Fill the remaining characters in 'dest' with null characters if 'n' is
	 * still greater than zero */
	while (n > 0)
	{
		// Fill with null character and increment destination pointer
		*dest++ = '\0';
		n--;
	}
	return (dest_start); // Return a pointer to the beginning of 'dest'
}
