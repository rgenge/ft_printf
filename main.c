
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf.c"
#include "ft_printf_utils.c"

int main(void)
{
// int fd;
// char *c ;
 int i;
 int j;

// i=0;

j=ft_printf ("\n%c%d%u%s:",'i',123456789,123456789, "v");
printf("%d", j);

i =   printf("\n%c%d%u%s:",'i',123456789,123456789, "v");
printf("%d", i);

}
