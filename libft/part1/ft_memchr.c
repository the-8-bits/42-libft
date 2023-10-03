/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:45 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:18:58 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		unchar;

	*ptr = s; // Convert the pointer to an unsigned char pointer
	unchar = (unsigned char)c; // Convert the character to an unsigned char
	while (n-- > 0)
	{
		if (*ptr == unchar)
			return ((void *)ptr); // Character found, return pointer to it
		ptr++;
	}
	return (NULL); // Character not found
}
