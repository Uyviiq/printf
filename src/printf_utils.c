/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:58:19 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/28 10:37:57 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	print_char(t_data *data, char c)
{
	int	prev;

	prev = data->count;
	data->count += write(1, &c, 1);
	if (prev > data->count)
		return (STATUS_ERROR);
	return (STATUS_OK);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_status	ft_putstr(t_data *data, const char *s)
{
	int	prev;

	prev = data->count;
	data->count += write(1, s, ft_strlen(s));
	if (prev > data->count)
		return (STATUS_ERROR);
	return (STATUS_OK);
}
