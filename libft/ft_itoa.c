/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:16 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/12 18:53:59 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				length;
	char			*str;

	length = ft_numlen(n);
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (n == 0)
		str[0] = '0';
	str[length--] = '\0';
	while (nb > 0)
	{
		str[length--] = '0' + nb % 10;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
