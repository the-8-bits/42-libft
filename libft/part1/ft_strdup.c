/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:36 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:09:52 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	// Calculate the size needed for the duplicate str, including the null termn
	size = ft_strlen(s) + 1;
	dup = (char *)malloc(size); // Allocate memory for the duplicate str
	if (!dup)
		return (NULL); // Return NULL if memory allocation fails
	// Copy the contents of the original str into the duplicate str
	ft_memcpy(dup, s, size);
	return (dup); // Return a pointer to the duplicate str
}
