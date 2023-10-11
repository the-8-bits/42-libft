/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:57:30 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/11 14:33:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t length)
{
	char	*dst;

	if (src == NULL)
		return (NULL);
	dst = (char *)malloc(length + 1);
	if (!dst)
		return (NULL);
	ft_strncpy(dst, (char *)src, length);
	dst[length] = '\0';
	return (dst);
}
