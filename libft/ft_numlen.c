/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:29:29 by codespace         #+#    #+#             */
/*   Updated: 2023/10/10 20:41:15 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_numlen(int n)
{
	unsigned int	len;
	long			buffer;

	len = 1;
	buffer = n;
	if (n < 0)
	{
		buffer *= -1;
		len++;
	}
	while (buffer >= 10)
	{
		buffer /= 10;
		len++;
	}
	return (len);
}
