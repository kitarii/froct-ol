/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:59:05 by ktiyari           #+#    #+#             */
/*   Updated: 2024/07/26 01:59:08 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "b_fractal.h"

void draw_fractal(t_fractal *fractal)
{
    mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
    if (!ft_strncmp(fractal->name, "mandelbrot", 11))
        mandelbrot(fractal);
    else if (!ft_strncmp(fractal->name, "julia", 6))
        julia(fractal);
    else if (!ft_strncmp(fractal->name, "burningship", 12))
        burningship(fractal);
    
}

int	main(int ac, char **av)
{
    t_fractal	fractal;
    if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 11)
        || !ft_strncmp(av[1], "burningship", 12))) 
        || (ac == 4 && !ft_strncmp(av[1],"julia", 6)))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
        if (!ft_strncmp(fractal.name, "julia", 6))
		{
			fractal.c.x = ft_atof(av[2]);
			fractal.c.y = ft_atof(av[3]);
		}
        draw_fractal(&fractal);
        event(&fractal);
        mlx_loop(fractal.mlx_ptr);
    }
    else 
        ft_putstr(ERR_MSG);
	
}
