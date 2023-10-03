/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:24 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/03 17:33:45 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	char	nl;

	if (s != NULL)
	{
		while (*s)
		{
			write(fd, s, 1); // Write one character at a time
			s++;
		}
		nl = '\n'; // Newline character
		write(fd, &nl, 1); // Write the newline character
	}
}
