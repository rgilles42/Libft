/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 05:54:35 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/30 05:54:47 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0)
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
		if (*s1++ == '\0')
			break ;
		n--;
	}
	return (0);
}
