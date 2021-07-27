/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:53:36 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/27 22:53:53 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bytes1;
	unsigned char	*bytes2;

	bytes1 = (unsigned char *)s1;
	bytes2 = (unsigned char *)s2;
	while (n--)
	{
		if (*bytes1++ != *bytes2++)
			return (*--bytes1 - *--bytes2);
	}
	return (0);
}
