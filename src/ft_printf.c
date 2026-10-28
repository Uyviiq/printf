/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:30:58 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/28 15:26:48 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	init_data(t_data *data, const char *fmt)
{
	if (!fmt || !data)
		return (STATUS_ERROR);
	data->fmt = fmt;
	data->fmt_index = 0;
	data->count = 0;
	return (STATUS_OK);
}

static t_status	call_handler(t_data *data)
{
	if (data->specifier == SPEC_CHAR
		|| data->specifier == SPEC_STRING
		|| data->specifier == SPEC_INTEGER
		|| data->specifier == SPEC_UNSIGNED
		|| data->specifier == SPEC_PERCENT)
		return (handle_basic_specifiers(data));
	else if (handle_address_specifiers(data))
		return (STATUS_ERROR);
	return (STATUS_OK);
}

static t_status	handle_format(t_data *data)
{
	data->fmt_index++;
	if (data->fmt[data->fmt_index] == '\0')
		return (STATUS_ERROR);
	if (parse_format(data))
	{
		if (data->fmt[data->fmt_index] == '\0')
			return (STATUS_ERROR);
		else if (print_char(data, '%'))
			return (STATUS_ERROR);
	}
	else if (call_handler(data))
		return (STATUS_ERROR);
	return (STATUS_OK);
}

static int	handle_char(t_data *data, char c_fmt)
{
	if (print_char(data, c_fmt))
		return (PRINTF_ERROR);
	data->fmt_index++;
	return (STATUS_OK);
}

int	ft_printf(const char *fmt, ...)
{
	t_data	data;

	if (init_data(&data, fmt))
		return (PRINTF_ERROR);
	va_start(data.args, fmt);
	while (data.fmt[data.fmt_index])
	{
		if (data.fmt[data.fmt_index] == '%')
		{
			if (handle_format(&data))
			{
				va_end(data.args);
				return (PRINTF_ERROR);
			}
		}
		else if (handle_char(&data, data.fmt[data.fmt_index]))
		{
			va_end(data.args);
			return (PRINTF_ERROR);
		}
	}
	va_end(data.args);
	return (data.count);
}
