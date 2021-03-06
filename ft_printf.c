/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:08:03 by acosta-a          #+#    #+#             */
/*   Updated: 2022/05/19 14:03:31 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_print(va_list arg, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = len + ft_printchar(va_arg(arg, int));
	if (type == 'd' || type == 'i')
		len = len + ft_putnbr_len(va_arg(arg, int), 1);
	if (type == 'u')
		len = len + ft_uputnbr_len(va_arg(arg, int), 1);
	if (type == 's')
		len = len + ft_putstr_fd(va_arg(arg, char *), 1);
	if (type == '%')
		len = len + ft_printpercent();
	if (type == 'x')
		len = len + ft_puthex_len(va_arg(arg, int), 1, 0);
	if (type == 'X')
		len = len + ft_puthex_len(va_arg(arg, int), 1, 1);
	if (type == 'p')
		len = len + ft_putptr(va_arg(arg, unsigned long long), 1, 0);
	return (len);
}

int	ft_printf(const char *type, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, type);
	while (type[i] != '\0')
	{
		if (type[i] == '%')
		{
			i++;
			len = len + check_print(arg, type[i]);
		}
		else
		{
			ft_printchar (type[i]);
			len++;
		}
		i++;
	}
	va_end (arg);
	return (len);
}
