/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:47:26 by ktiyari           #+#    #+#             */
/*   Updated: 2024/07/25 22:47:28 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

int	ft_closer(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	exit(0);
}

int	mouse(int key, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (key == 5)
		fractal->zoom *= 1.1;
	else if (key == 4)
		fractal->zoom /= 1.1;
	draw_fractal(fractal);
	return (0);
}

void	move(t_fractal *fractal, int key)
{
	if (key == 65361)
		fractal->offset_x += (0.5 * fractal->zoom);
	if (key == 65363)
		fractal->offset_x -= (0.5 * fractal->zoom);
	if (key == 65364)
		fractal->offset_y += (0.5 * fractal->zoom);
	if (key == 65362)
		fractal->offset_y -= (0.5 * fractal->zoom);
}

void	change_color(int key, t_fractal *fractal)
{
	if (key == 65436)
	{
		fractal->color1 = 0xE3A5C7;
		fractal->color2 = 0xFFDFD6;
	}
	if (key == 65433)
	{
        fractal->color1 = 0x134B70;
		fractal->color2 = 0x508C9B;
	}
	if (key == 65437)
	{
		fractal->color1 = 0xD0B8A8;
		fractal->color2 = 0x8D493A;
	}
	if (key == 65430)
	{
		fractal->color1 = 0x6B8A7A;
		fractal->color2 = 0x254336;
	}
}

int	key_handler(int key, t_fractal *fractal)
{
	if (key == 65307)
		ft_closer(fractal);
	if (key == 65436 || key == 65430 || key == 65433 || key == 65437)
		change_color(key, fractal);
	if (key == 65361 || key == 65363 || key == 65364 || key == 65362)
		move(fractal, key);
	draw_fractal(fractal);
	return (0);
}

void event(t_fractal *fractal)
{
    mlx_key_hook(fractal->win_ptr, key_handler, fractal);
    mlx_mouse_hook(fractal->win_ptr, mouse, fractal);
    mlx_hook(fractal->win_ptr, 17, 0, ft_closer, fractal);
}

