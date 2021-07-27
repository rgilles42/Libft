/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:47:05 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/27 22:47:07 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*copybuffer;

	copybuffer = (char *)dest;
	if (!src || !dest)
		return (NULL);
	while (n--)
	{
		*copybuffer++ = *(char *)(src++);
	}
	return (dest);
}
