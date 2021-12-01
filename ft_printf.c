/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:11:12 by ymirna            #+#    #+#             */
/*   Updated: 2021/11/27 19:55:31 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_arg(const char	c, va_list	ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(ap, int));
	if (c == 's')
		i = ft_putstr(va_arg(ap, char *));
	if (c == 'p')
		i = ft_hex_p(va_arg(ap, void *));
	if (c == 'd' || c == 'i')
		i = ft_itoa_ult(va_arg(ap, int), 0);
	if (c == 'u')
		i = ft_itoa_ult(0, va_arg(ap, unsigned int));
	if (c == 'x')
		i = ft_itoa_h(va_arg(ap, unsigned int), 0, NULL);
	if (c == 'X')
		i = ft_itoa_h(va_arg(ap, unsigned int), 1, NULL);
	if (c == '%')
	{
		write(1, "%", 1);
		i = 1;
	}
	return (i);
}

int	ft_printf(const char	*form, ...)
{
	int		ret;
	size_t	i;
	size_t	y;
	va_list	ap;

	ret = 0;
	i = 0;
	y = 0;
	va_start(ap, form);
	while (form[i])
	{
		if (form[i] != '%')
		{
			write(1, &form[i++], 1);
			ret++;
		}
		else
		{
			i++;
			y = ft_check_arg(form[i++], ap);
			ret = ret + y;
		}
	}
	va_end(ap);
	return (ret);
}
