/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:07:55 by acosta-a          #+#    #+#             */
/*   Updated: 2022/05/13 01:47:36 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //deletar

int			check_print(va_list args,const char type);
int			ft_print(const char *type, ...);

size_t		ft_strlen(const char *str);
int			ft_printchar(int c);
int			ft_putstr_nbr(char *s, int fd, int len);
int			ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_putnbr_len(int n, int fd);
int			ft_uputnbr_len(unsigned int n, int fd);
int			ft_printpercent(void);

#endif
