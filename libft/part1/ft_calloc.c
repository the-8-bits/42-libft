/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:55 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/06 14:08:58 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		total;
	void		*buffer;

	total = nmemb * size;
	buffer = malloc(total);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, total);
	return (buffer);
}
