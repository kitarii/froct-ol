/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:01:07 by ktiyari           #+#    #+#             */
/*   Updated: 2024/07/26 02:01:10 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "b_fractal.h"

void	burningship(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->z.x = 0.0;
			fractal->z.y = 0.0;
			fractal->c.x = (scale_range(x, WIDTH, X, Y) * fractal->zoom) + fractal->offset_x;
			fractal->c.y = (scale_range(y, HEIGHT, Y, X) * fractal->zoom) + fractal->offset_y;
			handle_pixel(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img.img_ptr, 0, 0);
}

void	mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->z.x = 0.0;
			fractal->z.y = 0.0;
			fractal->c.x = (scale_range(x, WIDTH, Y, X) * fractal->zoom) + fractal->offset_x;
			fractal->c.y = (scale_range(y, HEIGHT, X, Y) * fractal->zoom) + fractal->offset_y;
			handle_pixel(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img.img_ptr, 0, 0);
}

void	julia(t_fractal *fractal)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->z.x = (scale_range(x, WIDTH, Y, X) * fractal->zoom) + fractal->offset_x;
			fractal->z.y = (scale_range(y, HEIGHT, X, Y) * fractal->zoom) + fractal->offset_y;
			handle_pixel(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img.img_ptr, 0, 0);
}
