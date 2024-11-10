/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:11:28 by ktiyari           #+#    #+#             */
/*   Updated: 2024/07/25 21:11:30 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTAL_H
#define FRACTAL_H

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERR_MSG "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH 800
#define HEIGHT 800
# define ESCAPE 4  
# define X 2
# define Y -2

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*adr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	int			iter;
	t_img		img;
	t_complex	z;
	t_complex	c;
	double		x;
	double		y;
	double 		zoom;
	unsigned int	color1;
	unsigned int	color2;
	double			offset_x;
	double			offset_y;

}				t_fractal;

typedef struct vars
{
	int				i;
	double			nb;
	int				s;
	int				k;
}					t_vars;


int			ft_strncmp(char *s1, char *s2, size_t n);
void		ft_putstr(char *str);
void		fractal_init(t_fractal *fractal);
void		draw_fractal(t_fractal *fractal);
void		mandelbrot(t_fractal *fractal);
double		scale_range(double val, double in_max, double out_min, double out_max);
void		handle_pixel(int x, int y, t_fractal *fractal);
t_complex	oper_complex(t_complex z, t_complex c);
void		put_pixel(t_fractal *fractal, int x, int y, int color, int i);
void		event(t_fractal *fractal);
double		ft_atof(char *str);
void		julia(t_fractal *fractal);

#endif