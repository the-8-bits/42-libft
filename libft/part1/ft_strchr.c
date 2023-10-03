/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:38 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:10:35 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s); // Found the character, return its pointer
		s++; // Move to the next character in the string
	}
	// Check for the null terminator (end of string)
	if ((char)c == '\0')
		return ((char *)s); // Character is the null terminator
	return (NULL); // Character not found in the string
}
