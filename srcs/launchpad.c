/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:46:43 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/09 17:46:45 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	init(t_printf *myprintf)
{
	myprintf->minus = 0;
	myprintf->zero = 0;
	myprintf->field_len = -1;
	myprintf->prec = -1;
	myprintf->conv = 0;
	myprintf->is_l = 0;
}

void	get_parsing_params2(const char *to_parse, t_printf *myprintf)
{
	if (to_parse[myprintf->i] == '.')
	{
		if (to_parse[++(myprintf->i)] == '*')
			myprintf->prec = va_arg(myprintf->args, int);
		else
			myprintf->prec = ft_atoi(to_parse + myprintf->i);
		while (ft_strchr("0123456789*", to_parse[myprintf->i]))
			(myprintf->i)++;
		if (myprintf->prec < 0)
			myprintf->prec = -1;
	}
	while (ft_strchr("lh", to_parse[myprintf->i]))
	{
		if (to_parse[myprintf->i] == 'l')
			myprintf->is_l++;
		if (to_parse[myprintf->i] == 'h')
			myprintf->is_l--;
		myprintf->i++;
	}
	if (ft_strchr("cspdiuxX%", to_parse[myprintf->i]))
		myprintf->conv = to_parse[(myprintf->i)++];
}

void	get_parsing_params(const char *to_parse, t_printf *myprintf)
{
	while (to_parse[myprintf->i] == '-' || to_parse[myprintf->i] == '0')
	{
		if (to_parse[myprintf->i] == '-')
			myprintf->minus = to_parse[(myprintf->i)++];
		if (to_parse[myprintf->i] == '0')
			myprintf->zero = to_parse[(myprintf->i)++];
	}
	if (ft_strchr("123456789*", to_parse[myprintf->i]))
	{
		if (to_parse[(myprintf->i)] == '*')
			myprintf->field_len = va_arg(myprintf->args, int);
		else
			myprintf->field_len = ft_atoi(to_parse + myprintf->i);
		while (ft_strchr("1234567890*", to_parse[myprintf->i]))
			(myprintf->i)++;
		if (myprintf->field_len < 0)
		{
			myprintf->field_len = -(myprintf->field_len);
			myprintf->minus = '-';
		}
	}
	get_parsing_params2(to_parse, myprintf);
}

int		display(t_printf *myprintf)
{
	if (myprintf->conv == 'c')
		return (print_c(myprintf, 0));
	else if (myprintf->conv == '%')
		return (print_c(myprintf, '%'));
	else if (myprintf->conv == 's')
		return (print_s(myprintf));
	else if (myprintf->conv == 'p')
		return (print_nb_base(myprintf, "0123456789abcdef", 0, 1));
	else if ((myprintf->conv == 'd') || (myprintf->conv == 'i'))
		return (print_nb_base(myprintf, "0123456789", 1, myprintf->is_l));
	else if (myprintf->conv == 'u')
		return (print_nb_base(myprintf, "0123456789", 0, myprintf->is_l));
	else if (myprintf->conv == 'x')
		return (print_nb_base(myprintf, "0123456789abcdef", 0, myprintf->is_l));
	else if (myprintf->conv == 'X')
		return (print_nb_base(myprintf, "0123456789ABCDEF", 0, myprintf->is_l));
	return (0);
}

int		complete_field_len(t_printf *myprintf, int nbwritten)
{
	char	c;
	int		i;

	i = nbwritten;
	c = ' ';
	if (myprintf->zero && !myprintf->minus
		&& !(ft_strchr("pdiuxX", myprintf->conv) && myprintf->prec != -1))
		c = '0';
	while (i++ < myprintf->field_len)
		write(1, &c, 1);
	return (myprintf->field_len - nbwritten);
}
