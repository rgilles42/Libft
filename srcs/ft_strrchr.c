/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 05:42:20 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/30 05:42:32 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*toreturn;

	toreturn = 0;
	while (*str)
		if (*str++ == (char)c)
			toreturn = (char *)str - 1;
	if (*str == (char)c)
		toreturn = (char *)str;
	return (toreturn);
}
