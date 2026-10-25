#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdarg.h>

typedef enum e_specifier
{
    SPEC_CHAR,
    SPEC_STRING,
    SPEC_POINTER,
    SPEC_INTEGER,
    SPEC_UNSIGNED,
    SPEC_HEX_LOWER,
    SPEC_HEX_UPPER,
    SPEC_PERCENT,
    SPEC_INVALID
}   t_specifier;

typedef enum e_status 
{
   STATUS_OK = 0,
   STATUS_ERROR = 1337,
   PRINTF_ERROR = -1
}            t_status;

typedef struct s_data 
{
      const char *fmt;
      int fmt_index;
      int  count; 
      va_list  args;
      t_specifier specifier;
}              t_data;

// prototypes
int ft_printf(const char *fmt, ...);
t_status    print_char(t_data *data, char c);
t_status    ft_putstr(t_data *data,const char *s);
size_t    ft_strlen(const char *s);
t_status    parse_format(t_data *data);
void    print_string(t_data *data);
void    print_integer(t_data *data);
void    print_unsigned(t_data *data);
void    print_pointer(t_data *data);
void    print_hex_lower(t_data *data);
void    print_hex_upper(t_data *data);
void    print_percent(t_data *data);

#endif 
