/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:22 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/04 15:48:06 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	idx;
	size_t	count;
	int		is_inside_word;

	idx = 0;
	count = 0;
	is_inside_word = 0;
	while (s[idx])
	{
		if (s[idx] != c && !is_inside_word)
		{
			is_inside_word = 1;
			count++;
		}
		else if (s[idx] == c && is_inside_word)
			is_inside_word = 0;
		idx++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, size_t length)
{
	char	*dst;

	*dst = (char *)malloc(length + 1);
	if (!dst)
		return (NULL);
	ft_strncpy(dst, src, length);
	dst[length] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		is_inside_word;
	size_t	char_index;
	size_t	split_index;

	if (!s)
		return (NULL);
	**split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	char_index = 0;
	split_index = 0;
	is_inside_word = 0;
	while (s[char_index])
	{
		if (s[char_index] != c && !is_inside_word)
		{
			is_inside_word = 1;
			split[split_index++] = ft_strndup(s + char_index, 1);
		}
		else if (s[char_index] == c && is_inside_word)
			is_inside_word = 0;
		char_index++;
	}
	split[split_index] = NULL;
	return (split);
}
