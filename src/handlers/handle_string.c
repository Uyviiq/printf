/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:00:24 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/28 09:59:43 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	print_string(t_data *data)
{
	char	*str;

	if (data->specifier == SPEC_CHAR)
		return (print_char(data, va_arg(data->args, int)));
	else
	{
		str = va_arg(data->args, char *);
		if (!str)
			return (ft_putstr(data, "(null)"));
		return (ft_putstr(data, str));
	}
}
