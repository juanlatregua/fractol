/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:31:10 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/11/26 12:56:41 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static t_rgb	*create_palette_part1(void);
static t_rgb	*create_palette_part2(void);
static t_rgb	*get_palette_colorful(void);

uint32_t	monocromatic(t_fractal *f)
{
	t_rgb		*palette;
	double		l;
	uint32_t	color;

	palette = malloc(sizeof(t_rgb));
	if (!palette)
		return (0);
	if (f->smooth)
		l = smooth_color(f);
	else
		l = f->i;
	*palette = (t_rgb){
		(255 / f->max_iter) * l,
		(255 / f->max_iter) * l,
		(255 / f->max_iter) * l,
	};
	color = rgb(*palette);
	free(palette);
	return (color);
}

uint32_t	colorfull(t_fractal *f)
{
	t_rgb		*palette;
	double		l;
	t_rgb		index;
	t_rgb		next_index;
	uint32_t	color;

	palette = get_palette_colorful();
	if (!palette)
		return (0);
	if (f->smooth)
		l = smooth_color(f);
	else
		l = f->i;
	index = palette[(int)floor(l) % 92];
	next_index = palette[((int)floor(l) + 1) % 92];
	color = interpolate_color(index, next_index, l - floor(l));
	free(palette);
	return (color);
}

static t_rgb	*create_palette_part1(void)
{
	t_rgb	*palette1;
	t_rgb	colors1[53];

	palette1 = malloc(sizeof(t_rgb) * 53);
	if (!palette1)
		return (NULL);
	t_rgb temp_colors1[53] = {
	{255, 0, 0}, {255, 8, 0}, {255, 16, 0}, {255, 24, 0}, {255, 32, 0},
	{255, 40, 0}, {255, 48, 0}, {255, 56, 0}, {255, 64, 0}, {255, 72, 0},
	{255, 80, 0}, {255, 88, 0}, {255, 96, 0}, {255, 104, 0}, {255, 112, 0},
	{255, 128, 0}, {255, 144, 0}, {255, 160, 0}, {255, 176, 0},
	{255, 192, 0}, {255, 208, 0}, {255, 224, 0}, {255, 240, 0},
	{255, 255, 0}, {239, 255, 0}, {223, 255, 0}, {207, 255, 0},
	{191, 255, 0}, {175, 255, 0}, {159, 255, 0}, {143, 255, 0},
	{127, 255, 0}, {111, 255, 0}, {95, 255, 0}, {79, 255, 0},
	{63, 255, 0}, {47, 255, 0}, {31, 255, 0}, {16, 255, 0}, {0, 255, 0},
	{0, 255, 8}, {0, 255, 16}, {0, 255, 24}, {0, 255, 32}, {0, 255, 40},
	{0, 255, 48}, {0, 255, 56}, {0, 255, 64}, {0, 255, 72}, {0, 255, 80},
	{0, 255, 88}, {0, 255, 96}, {0, 255, 104},
	};
	memcpy(colors1, temp_colors1, sizeof(temp_colors1));
	memcpy(palette1, colors1, sizeof(colors1));
	return (palette1);
}

static t_rgb	*create_palette_part2(void)
{
	t_rgb	*palette2;
	t_rgb	colors2[52];

	palette2 = malloc(sizeof(t_rgb) * 52);
	if (!palette2)
		return (NULL);
	t_rgb temp_colors2[52] = {
	{0, 255, 112}, {0, 255, 128}, {0, 255, 136}, {0, 255, 144},
	{0, 255, 152}, {0, 255, 160}, {0, 255, 168}, {0, 255, 176},
	{0, 255, 184}, {0, 255, 192}, {0, 255, 200}, {0, 255, 216},
	{0, 255, 232}, {0, 255, 240}, {0, 255, 255}, {0, 247, 255},
	{0, 239, 255}, {0, 231, 255}, {0, 223, 255}, {0, 215, 255},
	{0, 207, 255}, {0, 199, 255}, {0, 191, 255}, {0, 183, 255},
	{0, 175, 255}, {0, 167, 255}, {0, 159, 255}, {0, 151, 255},
	{0, 142, 255}, {0, 127, 255}, {0, 119, 255}, {0, 111, 255},
	{0, 103, 255}, {0, 95, 255}, {0, 63, 255}, {0, 31, 255},
	{0, 0, 255}, {32, 0, 224}, {224, 0, 208}, {64, 0, 192},
	{224, 0, 176}, {96, 0, 160}, {224, 0, 144}, {128, 0, 128},
	{224, 0, 112}, {160, 0, 96}, {176, 0, 80}, {192, 0, 64},
	{207, 0, 48}, {223, 0, 32}, {239, 0, 16}, {255, 0, 0}
	};
	memcpy(colors2, temp_colors2, sizeof(temp_colors2));
	memcpy(palette2, colors2, sizeof(colors2));
	return (palette2);
}

static t_rgb	*get_palette_colorful(void)
{
	t_rgb	*palette1;
	t_rgb	*palette2;
	t_rgb	*palette;

	palette1 = create_palette_part1();
	if (!palette1)
		return (NULL);
	palette2 = create_palette_part2();
	if (!palette2)
		return (NULL);
	palette = malloc(sizeof(t_rgb) * 105);
	if (!palette)
	{
		free(palette1);
		free(palette2);
		return (NULL);
	}
	memcpy(palette, palette1, sizeof(t_rgb) * 53);
	memcpy(palette + 53, palette2, sizeof(t_rgb) * 52);
	free(palette1);
	free(palette2);
	return (palette);
}
