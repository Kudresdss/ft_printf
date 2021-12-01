/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csdiu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:16:17 by ymirna            #+#    #+#             */
/*   Updated: 2021/11/27 19:31:59 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char	c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	return (i);
}

static size_t	ft_rank_itoa(unsigned int	n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_put_itoa(char	*str, unsigned int	n, int	ng, size_t	i)
{
	i--;
	str[i + ng + 1] = '\0';
	if (ng == 1)
		i++;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	if (ng == 1)
		str[0] = '-';
	return (str);
}

int	ft_itoa_ult(int	n, unsigned int	ntrue)
{
	size_t			i;
	int				ret;
	int				ng;
	char			*str;

	ng = 0;
	if (n < 0)
	{
		n = -n;
		ng++;
	}
	if (n != 0)
		ntrue = (unsigned int)n;
	i = ft_rank_itoa(ntrue);
	str = (char *)malloc(sizeof(char) * (i + ng + 1));
	if (str == NULL)
		return (0);
	ret = ft_putstr(ft_put_itoa(str, ntrue, ng, i));
	free (str);
	return (ret);
}
