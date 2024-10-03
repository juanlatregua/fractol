/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:31:02 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/10/03 09:31:03 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fractol.h"

double	smooth_color(t_fractal *f)
{
	double	zn;
	double	nu;

	zn = log(f->z.real * f->z.real + f->z.img * f->z.img) / 2.0;
	nu = log(zn / log(2)) / log(2);
	if (f->i < f->max_iter)
		return (f->i + 1 - nu);
	else if (f->i > 0)
		return (f->max_iter);
	else
		return (0.0);
}
uint32_t	interpolate_color(t_rgb first, t_rgb second, double t)
{
	t_rgb	new_color;

	new_color.r = first.r + (second.r - first.r) * t;
	new_color.g = first.g + (second.g - first.g) * t;
	new_color.b = first.b + (second.b - first.b) * t;
	return (rgb(new_color));
}

uint32_t	rgb(t_rgb color)
{
	return (color.r << 24 | color.g << 16 | color.b << 8 | 255);
}
