/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 20:08:23 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/23 20:08:25 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*copybuffer;

	copybuffer = (unsigned char *)s;
	while (n-- > 0)
		*copybuffer++ = (unsigned char)c;
	return (s);
}
