/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:48:29 by gabrodri          #+#    #+#             */
/*   Updated: 2023/10/04 15:45:53 by gabrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void recursion(int n, int fd)
{
    if (n < 0) {
        ft_putchar_fd('-', fd);
        n = -n; // Make n positive for the recursion
    }
    if (n >= 10)
        recursion(n / 10, fd); // Recursive call for the quotient
    ft_putchar_fd('0' + (n % 10), fd); // Print the last digit
}

void ft_putnbr_fd(int n, int fd) {
    if (n == 0)
        ft_putchar_fd('0', fd);
	else
        recursion(n, fd);
}
