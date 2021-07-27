/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigits_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:05:32 by rgilles           #+#    #+#             */
/*   Updated: 2020/06/08 15:05:35 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbdigits_base(unsigned long long int nb, int base)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
