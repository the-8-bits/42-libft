/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:54 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:15:49 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char *str)
{
	while (*str)
	{
		if (!(((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
				|| (*str >= '0' && *str <= '9')))
			return (0);
		str++;
	}
	return (1);
}