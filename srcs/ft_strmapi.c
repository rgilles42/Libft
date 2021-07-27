/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:07:55 by rgilles           #+#    #+#             */
/*   Updated: 2020/04/08 16:08:08 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*toret;
	unsigned int	i;

	toret = (char *)malloc(ft_strlen(s) + 1);
	if (!s || !toret)
		return (NULL);
	i = -1;
	while (s[++i])
		toret[i] = f(i, s[i]);
	toret[i] = 0;
	return (toret);
}
