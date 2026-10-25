/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:00:24 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/25 19:25:53 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"


void    print_string(t_data *data)
{
    if (data->specifier == SPEC_CHAR)
        print_char(data, data->fmt[data->fmt_index]);
    else 
        ft_putstr(data, va_arg(data->args, char *));
}