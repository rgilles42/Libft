/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:52:47 by rgilles           #+#    #+#             */
/*   Updated: 2020/04/08 19:52:49 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	u_n;

	u_n = (unsigned int)nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		u_n = (unsigned int)(-1 * nb);
	}
	if (u_n > 9)
	{
		ft_putnbr_fd(u_n / 10, fd);
		ft_putchar_fd('0' + u_n % 10, fd);
	}
	else
		ft_putchar_fd('0' + u_n, fd);
}
