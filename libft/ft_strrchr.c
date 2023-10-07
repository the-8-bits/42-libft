/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:12 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:21:28 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	// Initialize a pointer to track the last occurrence
	*last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = s; // Update the pointer when a match is found
		s++;
	}
	if ((char)c == '\0')
		// Return a pointer to the null terminator if c is '\0'
		return ((char *)s);
	// Return a pointer to the last occurrence or NULL if not found
	return ((char *)last_occurrence);
}
