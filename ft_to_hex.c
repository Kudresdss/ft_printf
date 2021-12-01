/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:52:00 by ymirna            #+#    #+#             */
/*   Updated: 2021/11/27 19:30:59 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_p(void	*ptr)
{
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	return (ft_itoa_h(0, 0, ptr) + 2);
}

int	ft_to_hex(int	hex)
{
	if (hex == 10)
		return ('a' - '0');
	if (hex == 11)
		return ('b' - '0');
	if (hex == 12)
		return ('c' - '0');
	if (hex == 13)
		return ('d' - '0');
	if (hex == 14)
		return ('e' - '0');
	if (hex == 15)
		return ('f' - '0');
	return (hex);
}
