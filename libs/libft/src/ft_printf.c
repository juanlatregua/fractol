/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:59:42 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/10/03 09:59:53 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_printf(const char *str, ...)
{
	t_block	b;

	ft_bzero(&b, sizeof(b));
	va_start(b.ap, str);
	while (str[b.i])
	{
		if (str[b.i] != '%')
			b.ret += write(1, &str[b.i++], 1);
		else
		{
			(b.i)++;
			reset_block_pf(&b);
			checkflags_pf(str, &b);
			checktypes_pf(str, &b);
		}
	}
	va_end(b.ap);
	reset_block_pf(&b);
	return (b.ret);
}
