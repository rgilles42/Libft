/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:08:33 by rgilles           #+#    #+#             */
/*   Updated: 2020/02/12 21:08:35 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	calculate(double nb, double approx, double prev_approx)
{
	if (approx == prev_approx)
		return (approx);
	return (calculate(nb, (approx + nb / approx) / 2, approx));
}

double			ft_sqrt(double nb)
{
	if (!nb)
		return (0);
	return (calculate(nb, 50, 0));
}
