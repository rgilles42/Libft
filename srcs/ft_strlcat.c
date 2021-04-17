/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:55:46 by rgilles           #+#    #+#             */
/*   Updated: 2020/02/10 15:55:52 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	char	*odst;
	char	*osrc;
	size_t	nleft;
	size_t	dlen;

	odst = dst;
	osrc = src;
	nleft = size;
	while (nleft-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	nleft = size - dlen;
	if (nleft == 0)
		return (dlen + ft_strlen(osrc));
	while (*src)
	{
		if (nleft != 1)
		{
			*dst++ = *src;
			nleft--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
