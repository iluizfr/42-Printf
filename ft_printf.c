/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-frei <lde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:09:45 by lde-frei          #+#    #+#             */
/*   Updated: 2025/11/14 14:59:56 by lde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_spect(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	check(char format, va_list *args)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_base(va_arg(*args, unsigned int), 10, "0123456789"));
	else if (format == 'x')
		return (ft_base(va_arg(*args, unsigned int), 16, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_base(va_arg(*args, unsigned int), 16, "0123456789ABCDEF"));
	else if (format == 'p')
		return (addres(va_arg(*args, void *)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (is_spect(format[i + 1]))
				count += check(format[++i], &args);
			else if (!is_spect(format[i + 1]))
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/* int main(void)
{
	ft_printf("[%d]", ft_printf("%s", "abcde"));
	printf("\n");

	ft_printf("%%");
	printf("\n");

	ft_printf("%c", 'Z');
	printf("\n");

	ft_printf("%i %d", 100, -100);
	printf("\n");

	ft_printf("[%d]", ft_printf("%i %d", 100, -100));
	printf("\n");

	unsigned n = 256; ft_printf("%u", n);
	printf("\n");

	ft_printf("[%x] [%X]", 100000, 100000);
	printf("\n");
	
	int a = 0; ft_printf("[%p]", &a); printf("[%p]", &a);

	//printf("[%kjm]");ft_printf("[%kjm]");

	return (0);
} */