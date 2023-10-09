/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:22 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/09 10:07:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	h_count_words(const char *s, char c)
{
	size_t	count;
	int		is_inside_word;

	count = 0;
	is_inside_word = 0;
	while (*s)
	{
		if (*s == c)
			is_inside_word = 0;
		else if (!is_inside_word)
		{
			is_inside_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (h_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (s[j] && s[j] != c)
				j++;
			split[i++] = ft_substr(s, 0, j);
			s += j;
		}
	}
	split[i] = NULL;
	return (split);
}
