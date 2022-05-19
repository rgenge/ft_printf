/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 08:57:39 by acosta-a          #+#    #+#             */
/*   Updated: 2022/05/19 13:44:40 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_putptr(unsigned long long n, int fd, int type)
{
	int					len;
	char				c[19];
	unsigned long long	nb;

	nb = n;
	len = 0;
	{
		if (nb == 0)
			return (ft_putstr_fd("(nil)", fd));
		while (nb > 0)
		{
			c[len++] = nb % 16;
			nb = nb / 16;
		}
	}
	return (ft_putstr_ptr (c, fd, len, type));
}

int	ft_putstr_ptr(char *s, int fd, int len, int type)
{
	int	i;

	i = len - 1;
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	write(fd, "0x", 2);
		len = len + 2;
	while (i >= 0)
	{
		if (s[i] <= 9)
			ft_putchar_fd(s[i--] + '0', fd);
		else
		{
			if (type == 0)
				ft_putchar_fd(s[i] - 10 + 'a', fd);
			i--;
		}
	}
	return (len);
}

int	ft_puthex_len(unsigned int n, int fd, int type)
{
	int				len;
	char			c[10];
	unsigned int	nb;

	nb = n;
	len = 0;
	{
		if (nb == 0)
		{
			ft_putchar_fd('0', fd);
			return (1);
		}
		while (nb > 0)
		{
			c[len++] = nb % 16;
			nb = nb / 16;
		}
	}
	return (ft_putstr_hex (c, fd, len, type));
}

int	ft_putstr_hex(char *s, int fd, int len, int type)
{
	int	i;

	i = len - 1;
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	while (i >= 0)
	{
		if (s[i] <= 9)
			ft_putchar_fd(s[i--] + '0', fd);
		else
		{
			if (type == 0)
				ft_putchar_fd(s[i] - 10 + 'a', fd);
			if (type == 1)
				ft_putchar_fd(s[i] - 10 + 'A', fd);
			i--;
		}
	}
	return (len);
}
