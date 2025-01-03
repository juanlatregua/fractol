/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:30:08 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/11/25 19:21:41 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_julia(t_fractal *f)
{
	if (!f)
		return;
	double	tmp;

	f->z.real = (f->x - WIDTH / 2) * f->zoom / WIDTH + f->mv_h;
	f->z.img = (f->y - HEIGHT / 2) * f->zoom / WIDTH + f->mv_v;
	f->c.real = f->j_args.real + f->j_nm;
	f->c.img = f->j_args.img + f->j_nm;
	f->i = -1;
	while (++f->i < f->max_iter)
	{
		if ((f->z.real * f->z.real + f->z.img * f->z.img) >= 4.0)
			break ;
		tmp = 2.0 * f->z.real * f->z.img + f->c.img;
		f->z.real = f->z.real * f->z.real - f->z.img * f->z.img + f->c.real;
		f->z.img = tmp;
	}
	put_pixel(f);
}
