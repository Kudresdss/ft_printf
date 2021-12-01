/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:31:18 by ymirna            #+#    #+#             */
/*   Updated: 2021/11/27 19:46:29 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char	*form, ...);
int	ft_putchar(char	c);
int	ft_putstr(char	*str);
int	ft_itoa_ult(int	n, unsigned int	ntrue);
int	ft_itoa_h(unsigned int	nhex, int	x, void	*ptr);
int	ft_hex_p(void	*ptr);
int	ft_to_hex(int	hex);

#endif