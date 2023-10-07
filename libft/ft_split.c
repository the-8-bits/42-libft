/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:22 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/06 16:01:23 by gabrodri         ###   ########.fr       */
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

void	h_actual_split(char const *s, char c, char **split, size_t split_index)
{
	size_t	word_length;

	word_length = 0;
	while (s[word_length] && s[word_length] != c)
		word_length++;
	split[split_index++] = ft_strndup(s, word_length);
	s += word_length;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	split_index;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (h_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	split_index = 0;
	while (*s)
	{
		if (*s != c)
			h_actual_split(s, c, split, split_index);
		else
			s++;
	}
	split[split_index] = NULL;
	return (split);
}
