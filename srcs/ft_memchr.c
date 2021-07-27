/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 20:15:07 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/27 20:15:10 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*memzone;

	memzone = (unsigned char *)s;
	while (n--)
		if (*memzone++ == (unsigned char)c)
			return (--memzone);
	return (0);
}
