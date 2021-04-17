/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:49:22 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 11:49:24 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	print_s(t_printf *myprintf)
{
	const char	*str;
	int			len;
	int			nbtofillfield;

	nbtofillfield = 0;
	str = va_arg(myprintf->args, const char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (myprintf->prec >= 0 && myprintf->prec < len)
	{
		if (myprintf->field_len > myprintf->prec && !myprintf->minus)
			nbtofillfield = complete_field_len(myprintf, myprintf->prec);
		write(1, str, myprintf->prec);
		if (myprintf->field_len > myprintf->prec && myprintf->minus)
			nbtofillfield = complete_field_len(myprintf, myprintf->prec);
		return (myprintf->prec + nbtofillfield);
	}
	if (myprintf->field_len > len && !myprintf->minus)
		nbtofillfield = complete_field_len(myprintf, len);
	write(1, str, len);
	if (myprintf->field_len > len && myprintf->minus)
		nbtofillfield = complete_field_len(myprintf, len);
	return (len + nbtofillfield);
}
