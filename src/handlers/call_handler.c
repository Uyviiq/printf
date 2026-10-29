/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:51:37 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/28 10:22:39 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	handle_basic_specifiers(t_data *data)
{
	if (data->specifier == SPEC_CHAR || data->specifier == SPEC_STRING)
		return (print_string(data));
	else if (data->specifier == SPEC_INTEGER)
		return (print_signed(data, va_arg(data->args, int)));
	else if (data->specifier == SPEC_UNSIGNED)
		return (ft_putnbr_base(data, va_arg(data->args, unsigned int),
				"0123456789"));
	else if (data->specifier == SPEC_PERCENT)
		return (print_char(data, '%'));
	return (STATUS_OK);
}

t_status	handle_address_specifiers(t_data *data)
{
	void	*ptr;

	if (data->specifier == SPEC_POINTER)
	{
		ptr = va_arg(data->args, void *);
		if (!ptr)
			return (ft_putstr(data, "(nil)"));
		if (ft_putstr(data, "0x")
			|| ft_putnbr_base(data, (unsigned long)ptr,
				"0123456789abcdef"))
			return (STATUS_ERROR);
	}
	else if (data->specifier == SPEC_HEX_LOWER)
		return (ft_putnbr_base(data,
				(unsigned long)va_arg(data->args, unsigned int),
				"0123456789abcdef"));
	else if (data->specifier == SPEC_HEX_UPPER)
		return (ft_putnbr_base(data,
				(unsigned long)va_arg(data->args, unsigned int),
				"0123456789ABCDEF"));
	return (STATUS_OK);
}
