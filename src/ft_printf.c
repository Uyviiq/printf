/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:30:58 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/25 19:47:55 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static t_status init_data (t_data *data , const char *fmt)
{
    if (!fmt || !data)
        return (STATUS_ERROR);
    data->fmt = fmt;
    data->fmt_index = 0;
    data->count = 0;
    return (STATUS_OK);
}

int ft_printf(const char *fmt, ...)
{
    t_data data;
    char    c_fmt;

    if (init_data(&data, fmt))
        return (PRINTF_ERROR);
    va_start(data.args, fmt);
    while (data.fmt[data.fmt_index])
    {
        c_fmt = data.fmt[data.fmt_index];
        if (c_fmt == '%')
        {
            data.fmt_index++;
            if (parse_format(&data))
            {
                if (print_char(&data, '%') || print_char(&data, data.fmt[data.fmt_index - 1]))
                    return (PRINTF_ERROR);
                data.count += 2;
            }
            else {
                // cspdiuxX%
                if (data.specifier == SPEC_CHAR || data.specifier == SPEC_STRING)
                    print_string(&data);
                /*else if (data.specifier == SPEC_INTEGER)
                    print_integer(&data);
                else if (data.specifier == SPEC_UNSIGNED)
                    print_unsigned(&data);
                else if (data.specifier == SPEC_POINTER) 
                    print_pointer(&data);
                else if (data.specifier == SPEC_HEX_LOWER)
                    print_hex_lower(&data);
                else if (data.specifier == SPEC_HEX_UPPER)
                    print_hex_upper(&data);
                else if (data.specifier == SPEC_PERCENT)
                    print_percent(&data); */
            }
        }
        else 
        {
            if (print_char(&data, c_fmt))
            {
                va_end(data.args);
                return (PRINTF_ERROR);
            }
            data.count++;
            data.fmt_index++;
        }
    }
    va_end(data.args);
    return (data.count);
}