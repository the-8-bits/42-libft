/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:54 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/12 18:49:32 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (!(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			|| (c >= '0' && c <= '9')))
		return (0);
	return (1);
}