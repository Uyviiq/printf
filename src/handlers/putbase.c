/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:10 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/28 10:39:49 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	print_signed(t_data *data, int nbr)
{
	if (nbr < 0)
	{
		if (print_char(data, '-') || ft_putnbr_base(data, (unsigned long)(-(long)nbr),
			"0123456789") )
			return (STATUS_ERROR);
	}
	else if (ft_putnbr_base(data, (unsigned long)nbr, "0123456789"))
		return (STATUS_ERROR);
	return (STATUS_OK);
}

t_status	ft_putnbr_base(t_data *data, unsigned long nbr, char *base)
{
	unsigned long	base_len;
	char			digit;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return (STATUS_ERROR);
	if (nbr < 0)
	{
		if (print_char(data, '-'))
			return (STATUS_ERROR);
		nbr = -nbr;
	}
	if (nbr >= base_len)
	{
		if (ft_putnbr_base(data, nbr / base_len, base))
			return (STATUS_ERROR);
	}
	digit = base[nbr % base_len];
	if (print_char(data, digit))
		return (STATUS_ERROR);
	return (STATUS_OK);
}
