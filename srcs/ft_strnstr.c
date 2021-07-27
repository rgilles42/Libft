/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 06:29:39 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/30 06:29:51 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*s2)
	{
		return ((char *)s1);
	}
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j) < len)
		{
			if (!s2[j + 1])
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
