/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:58:33 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/08/21 22:19:01 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_pformats(va_list args, const char pformat)
{
	int	len;

	len = 0;
	if (pformat == 'c')
		len += ft_charput(va_arg(args, int));
	if (pformat == 's')
		len += ft_putstr(va_arg(args, char *));
	if (pformat == 'u')
		len += ft_num_unsign(va_arg(args, unsigned int));
	if (pformat == 'd' || pformat == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (pformat == 'p')
		len += ft_phexa(va_arg(args, void *));
	if (pformat == 'x' || pformat == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), pformat);
	if (pformat == '%')
		len += ft_charput('%');
	return (len);
}

static int	process(int *len, va_list args, const char *str, size_t *c)
{
	int	aux;

	if (str[*c] == '%')
	{
		aux = ft_pformats(args, str[*c + 1]);
		if (aux == -1)
			return (-1);
		else
			*len += aux;
		*c = *c + 1;
	}
	else
	{
		if (ft_charput(str[*c]) == -1)
			return (-1);
		else
			(*len)++;
	}
	(*c)++;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	size_t	c;

	c = 0;
	len = 0;
	va_start(args, str);
	while (str[c])
	{
		if (process(&len, args, str, &c) == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	return (va_end(args), len);
}
