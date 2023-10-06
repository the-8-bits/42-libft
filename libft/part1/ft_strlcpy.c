/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:32 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/06 14:07:23 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	char		*d;
	const char	*s;

	if (size == 0)
		return (ft_strlen(src));
	*d = dest;
	*s = src;
	while (*s && (size - 1) > 0)
	{
		*d++ = *s++;
		size--;
	}
	*d = '\0';
	return (ft_strlen(src));
}
