/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:58:55 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/11/25 10:34:25 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char	*str_dst;
	const char	*str_src;
	size_t	i;

	if (size == 0)
		return dst;

	str_dst = (char *)dst;
	str_src = (const char *)src;
	i = 0;

	if (!str_dst || !str_src)
		return (NULL);

	if (str_dst < str_src)
	{
		while (i < size)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	else
	{
		while (size--)
		{
			str_dst[size] = str_src[size];
		}
	}
	return (dst);
}
