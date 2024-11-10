/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:00:10 by ktiyari           #+#    #+#             */
/*   Updated: 2024/07/26 02:00:11 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "b_fractal.h"

double	scale_range(double val, double in_max, double out_min, double out_max)
{
	return (val * (out_max - out_min) / in_max + out_min);
}

t_complex	oper_complex(t_complex z, t_complex c)
{
	t_complex	res;

	res.x = fabs(z.x * z.x - z.y * z.y + c.x);
	res.y = fabs(2 * z.x * z.y + c.y);
	return (res);
}

void	put_pixel(t_fractal *fractal, int x, int y, int color, int i)
{
	char	*dst;

	dst = fractal->img.adr + (y * fractal->img.line_len + x * (fractal->img.bpp / 8));
	*(unsigned int*)dst = color * i/3200;
}

void	fractal_init(t_fractal *fractal)
{
    fractal->iter = 100;
	fractal->color1 = 0x8E8FFA;
	fractal->color2 = 0xFFF6E9;
	fractal->zoom = 1.0;
	fractal->mlx_ptr = mlx_init();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->name);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	}
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
    fractal->img.adr = mlx_get_data_addr(fractal->img.img_ptr,
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	int i;
	
	i = 0;
	while ((fractal->z.x * fractal->z.x + fractal->z.y
			* fractal->z.y < ESCAPE) && i < fractal->iter)
	{
		fractal->z = oper_complex(fractal->z, fractal->c);
		i++;
	}
	if (i == fractal->iter)
		put_pixel(fractal, x, y, fractal->color1, i);
	else
		put_pixel(fractal, x, y, fractal->color2, i );
}
