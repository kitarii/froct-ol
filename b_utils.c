/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:59:55 by ktiyari           #+#    #+#             */
/*   Updated: 2024/07/26 01:59:56 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "b_fractal.h"

void	initialize_variables(t_vars *vars)
{
	vars->i = 0;
	vars->nb = 0;
	vars->s = 1;
	vars->k = 0;
}

double	ft_atof(char *str)
{
	t_vars	var;

	initialize_variables(&var);
	while ((str[var.i] >= 9 && str[var.i] <= 13) || str[var.i] == ' ')
		var.i++;
	if (str[var.i] == '+' || str[var.i] == '-')
	{
		if (str[var.i] == '-')
			var.s = -1;
		var.i++;
	}
	while (str[var.i] && str[var.i] >= 48 && str[var.i] <= 57)
		var.nb = var.nb * 10 + (str[var.i++] - 48);
	if (str[var.i] == '.')
	{
		var.i++;
		while (str[var.i] && str[var.i] >= 48 && str[var.i] <= 57)
		{
			var.nb = var.nb * 10 + (str[var.i++] - 48);
			var.k++;
		}
	}
	while (var.k-- > 0)
		var.nb = var.nb / 10;
	return (var.nb * var.s);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
