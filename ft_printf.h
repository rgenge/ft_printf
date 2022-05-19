/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:07:55 by acosta-a          #+#    #+#             */
/*   Updated: 2022/05/19 14:02:55 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_printf(const char *type, ...);
int					ft_printchar(int c);
int					ft_putstr_nbr(char *s, int fd, int len, int flag);
int					ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_putnbr_len(int n, int fd);
int					ft_uputnbr_len(unsigned int n, int fd);
int					ft_printpercent(void);
int					ft_putstr_hex(char *s, int fd, int len, int type);
int					ft_puthex_len(unsigned int n, int fd, int type);
unsigned long long	ft_putptr(unsigned long long n, int fd, int type);
int					ft_putstr_ptr(char *s, int fd, int len, int type);

#endif
