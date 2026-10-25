#include "printf.h"
#include <stdio.h>

int main(void)
{
    char *name = "aziz";
    printf("%d\n",ft_printf("hello my name is %s\n",name));
}