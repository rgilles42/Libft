/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:01:49 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/30 19:01:51 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*toreturn;
	int		i;

	i = 0;
	toreturn = (char *)malloc(len + 1);
	if (!s || !toreturn)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + i] && len--)
		{
			toreturn[i] = s[start + i];
			i++;
		}
	}
	toreturn[i] = 0;
	return (toreturn);
}
