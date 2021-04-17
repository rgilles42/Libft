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

void	ft_putnbr_uns_fd(unsigned long long int u_n, int fd)
{
	if (u_n > 9)
	{
		ft_putnbr_uns_fd(u_n / 10, fd);
		ft_putchar_fd('0' + u_n % 10, fd);
	}
	else
		ft_putchar_fd('0' + u_n, fd);
}
