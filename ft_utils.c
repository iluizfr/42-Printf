/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:52:39 by lde-frei          #+#    #+#             */
/*   Updated: 2025/11/11 15:49:18 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + 48);
	return (count);
}

int	ft_base(t_long n, t_long value, char *symbols)
{
	int		count;

	count = 0;
	if (n >= value)
		count += ft_base(n / value, value, symbols);
	count += ft_putchar(symbols[n % value]);
	return (count);
}

int	addres(void *ptr)
{
	t_long	addres;
	int		count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	addres = (t_long)ptr;
	count += ft_putstr("0x");
	count += ft_base(addres, 16, "0123456789abcdef");
	return (count);
}
