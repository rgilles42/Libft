/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 22:44:48 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/30 22:44:50 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*toreturn;
	int		i;
	int		j;

	toreturn = malloc(ft_strlen(s1) + 1 + ft_strlen(s2));
	if (!s1 || !s2 || !toreturn)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i++])
		toreturn[i - 1] = s1[i - 1];
	while (s2[j++])
		toreturn[i + j - 2] = s2[j - 1];
	toreturn[i + j - 2] = 0;
	return (toreturn);
}
