/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:21:13 by rgilles           #+#    #+#             */
/*   Updated: 2020/04/08 14:21:19 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	setdims(size_t *nbchar, unsigned int *templ, unsigned int *abs, int n)
{
	*nbchar = 1;
	*templ = 1;
	if (n < 0)
		*abs = (unsigned int) -n;
	else
		*abs = (unsigned int)n;
	while (*abs / *templ >= 10)
	{
		*templ *= 10;
		(*nbchar)++;
	}
}

char	*ft_itoa(int n)
{
	size_t			flip;
	size_t			nbchar;
	unsigned int	abs;
	unsigned int	templ;
	char			*toret;

	flip = 0;
	if (n < 0)
		flip = 1;
	setdims(&nbchar, &templ, &abs, n);
	toret = (char *)malloc(nbchar + flip + 1);
	if (!toret)
		return (NULL);
	toret[nbchar + flip] = 0;
	if (flip)
		toret[0] = '-';
	while (nbchar > 0)
	{
		toret[flip++] = (char)((abs / templ) + '0');
		abs = abs % templ;
		templ /= 10;
		nbchar--;
	}
	return (toret);
}
