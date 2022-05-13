/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 08:57:39 by acosta-a          #+#    #+#             */
/*   Updated: 2022/05/13 01:47:11 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	ft_putstr_nbr(char *s, int fd, int len)
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
		ft_putchar_fd(s[i], fd);
		i--;
	}
	return (len);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int	ft_putnbr_len(int n, int fd)
{
	unsigned int	nb;
	int				len;
	char			c[10];

	len = 0;
	nb = (unsigned int)(n);
	{
		if (n == 0)
		{
			ft_putchar_fd('0', fd);
			len++;
		}
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nb = (unsigned int)(n * (-1));
			len++;
		}
		while (nb > 0)
		{
			c[len++] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	return (ft_putstr_nbr (c, fd, len));
}

int	ft_uputnbr_len(unsigned int n, int fd)
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
			len++;
		}
		while (nb > 0)
		{
			c[len++] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	return (ft_putstr_nbr (c, fd, len));
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
