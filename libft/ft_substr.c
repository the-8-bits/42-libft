/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:18 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 18:00:09 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	s_len = ft_strlen(s);
	if (start >= s_len)
		// Return an empty string if start is beyond the end of s
		return (ft_strdup(""));
	// Adjust len if it exceeds the available characters in s
	if (len > s_len - start)
		len = s_len - start;
	else
		len = len;
	// Allocate memory for the substring plus a null terminator
	*str = (char *)malloc(len + 1);
	if (!str)
		return (NULL); // Return NULL if memory allocation fails
	ft_memcpy(str, s + start, len); // Copy the substring from s to str
	str[len] = '\0'; // Null-terminate the substring
	return (str); // Return a pointer to the allocated substring
}
