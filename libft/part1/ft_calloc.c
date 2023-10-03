/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:55 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:17:44 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		total;
	void		*buffer;

	// Calculate the total size needed for the allocated memory
	total = nmemb * size;
	buffer = malloc(total); // Allocate memory for the array
	if (!buffer)
		return (NULL); // Return NULL if memory allocation fails
	// Initialize all bytes in the allocated memory to zero
	ft_bzero(buffer, total);
	// Return a pointer to the allocated and zero-initialized memory
	return (buffer);
}
