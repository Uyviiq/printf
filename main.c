#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>


int main(void)
{
    close(1);
    int count = ft_printf("%d",1234);
    dprintf(2,"count : %d\n",count);
}