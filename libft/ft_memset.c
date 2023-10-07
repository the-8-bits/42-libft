/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:40 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:19:43 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int value, size_t leng)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = block;
	i = 0;
	while (i < leng)
		*(ptr + i++) = value;
	return (block);
}
