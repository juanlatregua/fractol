/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:52:58 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/11/24 20:02:01 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*d;
	const char	*s;
	
	if (!dest || !src)
		return (NULL);

	d = (char *)dest;
	s = (const char *)src;
	
	while (size--)
		*d++ = *s++;
	return (dest);
}
