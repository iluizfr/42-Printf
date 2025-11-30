/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:10:04 by lde-frei          #+#    #+#             */
/*   Updated: 2025/11/11 15:21:38 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef unsigned long long	t_long;

int		ft_printf(const char *format, ...);
// Utils
int		ft_base(t_long n, t_long value, char *symbols);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		addres(void *ptr);
int		ft_putnbr(int n);

#endif