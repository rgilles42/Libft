/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:33:59 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/26 17:34:01 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*copybuffer;

	copybuffer = (char *)dest;
	while (n--)
	{
		*copybuffer++ = *(char *)(src++);
		if (*copybuffer == (char)c)
			return (copybuffer);
	}
	return (0);
}
