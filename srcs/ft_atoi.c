/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 07:00:03 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/30 07:01:07 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	oob_error(int sign)
{
	errno = ERANGE;
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	result;
	int				sign;

	sign = 1;
	result = 0;
	while (*nptr == '\f' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = 10 * result + *nptr - '0';
		nptr++;
		if (result > INT_MAX)
			break ;
	}
	if ((result == (unsigned int)INT_MAX + 1 && sign == -1)
		|| result <= INT_MAX)
		return (sign * result);
	return (oob_error(sign));
}
