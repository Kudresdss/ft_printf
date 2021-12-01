/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:33:02 by ymirna            #+#    #+#             */
/*   Updated: 2021/11/27 19:31:47 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	ft_rank_h(unsigned long	n)
{
	unsigned long	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*ft_put_h(char	*str, unsigned long	n, int	x, unsigned long	i)
{
	i--;
	str[i + 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = ft_to_hex(n % 16) + '0';
		if (x == 1)
		{
			if ('a' <= str[i] && str[i] <= 'f')
			{
				str[i] -= 32;
			}
		}
		i--;
		n = n / 16;
	}
	return (str);
}

int	ft_itoa_h(unsigned int	nhex, int	x, void	*ptr)
{
	unsigned long	i;
	unsigned long	y;
	int				ret;
	char			*str;

	i = (unsigned long) nhex;
	if (ptr)
		i = (unsigned long) ptr;
	y = i;
	i = ft_rank_h(i);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	ret = ft_putstr(ft_put_h(str, y, x, i));
	free (str);
	return (ret);
}
