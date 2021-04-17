/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:49:27 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/08 12:49:31 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printf(const char *to_parse, ...)
{
	t_printf		myprintf;

	va_start(myprintf.args, to_parse);
	myprintf.nbwritten = 0;
	myprintf.i = 0;
	while (to_parse[myprintf.i])
	{
		if (to_parse[myprintf.i] == '%')
		{
			if (to_parse[++(myprintf.i)] != 0)
			{
				init(&myprintf);
				get_parsing_params(to_parse, &myprintf);
				if (myprintf.conv)
					myprintf.nbwritten += display(&myprintf);
			}
		}
		else
		{
			write(1, to_parse + (myprintf.i)++, 1);
			(myprintf.nbwritten)++;
		}
	}
	va_end(myprintf.args);
	return (myprintf.nbwritten);
}
