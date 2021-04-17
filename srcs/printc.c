/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:24:04 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 11:24:06 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	print_c(t_printf *myprintf, char forcechar)
{
	int nbtofillfield;

	nbtofillfield = 0;
	if (myprintf->field_len > 1 && !myprintf->minus)
		nbtofillfield = complete_field_len(myprintf, 1);
	if (forcechar)
		ft_putchar(forcechar);
	else
		ft_putchar((unsigned char)va_arg(myprintf->args, int));
	if (myprintf->field_len > 1 && myprintf->minus)
		nbtofillfield = complete_field_len(myprintf, 1);
	return (1 + nbtofillfield);
}
