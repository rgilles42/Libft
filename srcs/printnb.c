/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:09:05 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 18:09:06 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	prefix(t_printf *myptf, int prl)
{
	if (prl == 1 && myptf->zero && myptf->prec == -1)
		write(1, "-", 1);
	if (myptf->conv == 'p' && myptf->zero && myptf->prec == -1)
		write(1, "0x", 2);
}

int		no_pr(t_printf *myptf, t_nb nb, int prl, char *chst)
{
	int	nbtofillfield;

	nbtofillfield = 0;
	if (myptf->field_len > (nb.nbd + prl) && !myptf->minus)
		nbtofillfield = complete_field_len(myptf, nb.nbd + prl);
	if (prl == 1 && (!myptf->zero || (myptf->zero && myptf->prec != -1)))
		write(1, "-", 1);
	if (myptf->conv == 'p'
		&& (!myptf->zero || (myptf->zero && myptf->prec != -1)))
		write(1, "0x", 2);
	if (!(nb.number == 0 && !myptf->prec))
		ft_putnbr_uns_base(nb.number, chst);
	if (myptf->field_len > (nb.nbd + prl) && myptf->minus)
		nbtofillfield = complete_field_len(myptf, nb.nbd + prl);
	return (nb.nbd + prl + nbtofillfield);
}

int		prnt(t_printf *myptf, t_nb nb, char *chst, int prl)
{
	int nbtofillfield;

	nbtofillfield = 0;
	nb.nbd = ft_nbdigits_base(nb.number, ft_strlen(chst));
	prefix(myptf, prl);
	if (nb.number == 0 && !myptf->prec)
		nb.nbd--;
	if (myptf->prec >= 0 && myptf->prec > nb.nbd)
	{
		if (myptf->field_len > (myptf->prec + prl) && !myptf->minus)
			nbtofillfield = complete_field_len(myptf, myptf->prec + prl);
		if (prl == 1 && (!myptf->zero || (myptf->zero && myptf->prec)))
			write(1, "-", 1);
		if (myptf->conv == 'p'
			&& (!myptf->zero || (myptf->zero && myptf->prec == -1)))
			write(1, "0x", 2);
		while (nb.nbd++ < myptf->prec)
			write(1, "0", 1);
		ft_putnbr_uns_base(nb.number, chst);
		if (myptf->field_len > (myptf->prec + prl) && myptf->minus)
			nbtofillfield = complete_field_len(myptf, myptf->prec + prl);
		return (myptf->prec + prl + nbtofillfield);
	}
	return (no_pr(myptf, nb, prl, chst));
}

void	print_nb_base_u(t_printf *myprintf, int is_l, t_nb *nb)
{
	if (is_l == 1)
		nb->number = va_arg(myprintf->args, unsigned long);
	else if (is_l == 2)
		nb->number = va_arg(myprintf->args, unsigned long long);
	else if (is_l == -1)
		nb->number = (unsigned short)va_arg(myprintf->args, int);
	else if (is_l == -2)
		nb->number = (unsigned char)va_arg(myprintf->args, int);
	else
		nb->number = va_arg(myprintf->args, unsigned int);
}

int		print_nb_base(t_printf *myprintf, char *charset, int is_sig, int is_l)
{
	t_nb			nb;
	int				prefix_len;
	long long int	temp;

	prefix_len = myprintf->conv == 'p' ? 2 : 0;
	if (is_sig)
	{
		if (is_l == 1)
			temp = va_arg(myprintf->args, long);
		else if (is_l == 2)
			temp = va_arg(myprintf->args, long long);
		else if (is_l == -1)
			temp = (short)va_arg(myprintf->args, int);
		else if (is_l == -2)
			temp = (char)va_arg(myprintf->args, int);
		else
			temp = va_arg(myprintf->args, int);
		nb.number = temp < 0 ? -temp : temp;
		prefix_len += temp < 0 ? 1 : 0;
	}
	else
		print_nb_base_u(myprintf, is_l, &nb);
	return (prnt(myprintf, nb, charset, prefix_len));
}
