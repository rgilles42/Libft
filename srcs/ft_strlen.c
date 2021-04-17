/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 23:48:27 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/30 14:32:26 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*charptr;
	size_t		i;

	charptr = str;
	i = 0;
	if (charptr)
		while (*charptr++)
			i++;
	return (i);
}
