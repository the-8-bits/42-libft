/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:21 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:27:53 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (s != NULL && f != NULL)
	{
		index = 0;
		while (*s)
		{
			// Call the function 'f' with the current index and character
			(*f)(index, s);
			s++; // Move to the next character
			index++; // Increment the index
		}
	}
}
