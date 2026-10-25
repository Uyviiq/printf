/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:29:32 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/25 19:56:04 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void init_table(t_specifier *specifiers, size_t size)
{
    size_t  i;

    i = 0;
    while (i < size)
    {
        *(specifiers + i) = SPEC_INVALID;
        i++;
    }
}

t_status    parse_format(t_data *data)
{
    char        c_fmt;
    t_specifier specifiers[128];

    c_fmt = (*data).fmt[(*data).fmt_index];
    init_table(specifiers, 128);
    specifiers['c'] = SPEC_CHAR;
    specifiers['s'] = SPEC_STRING;
    specifiers['p'] = SPEC_POINTER;
    specifiers['d'] = SPEC_INTEGER;
    specifiers['i'] = SPEC_INTEGER;
    specifiers['u'] = SPEC_UNSIGNED;
    specifiers['x'] = SPEC_HEX_LOWER;
    specifiers['X'] = SPEC_HEX_UPPER;
    specifiers['%'] = SPEC_PERCENT;
    if ((unsigned char)c_fmt >= 128)
        return (STATUS_ERROR);
    (*data).specifier = specifiers[(unsigned char)c_fmt];
    (*data).fmt_index++;
    if ((*data).specifier == SPEC_INVALID)
        return (STATUS_ERROR);
    return (STATUS_OK);
}