/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:19 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:45:37 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	char	*str;

	str = ft_strdup(s);
	if (!(str)) // Duplicate the input str 's' using 'ft_strdup'
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		str[idx] = (*f)(idx, str[idx]); // Apply the function 'f' to each char
		idx++;
	}
	return (str); // Return a pointer to the newly created str
}
