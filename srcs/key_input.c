/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_input.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 17:07:34 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 18:22:22 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void    quit(t_all *all)
{
	mlx_destroy_image(all->init, all->image_ptr);
	mlx_clear_window(all->init, all->win);
	exit(0);
}

void	move(t_all *all, int keycode)
{
	double	ratio;

	ratio = (all->fract->maxX - all->fract->minX) * (100 / 5.2);
	if (keycode == 124)
	{
		all->fract->minX += ratio / 100;
		all->fract->maxX += ratio / 100;
	}
	if (keycode == 123)
	{
		all->fract->minX -= ratio / 100;
		all->fract->maxX -= ratio / 100;
	}
	if (keycode == 126)
	{
		all->fract->minY -= ratio / 100;
		all->fract->maxY -= ratio / 100;
	}
	if (keycode == 125)
	{
		all->fract->minY += ratio / 100;
		all->fract->maxY += ratio / 100;
	}
	refresh_window(all);
}

void	reinit(t_all *all)
{
	all->fract->minX = -2;
	all->fract->maxX = 2;
	all->fract->minY = -1.25;
	all->fract->maxY = 1.25;
	refresh_window(all);
}

void	change_fract(t_all *all)
{
	all->ifract++;
	if (all->ifract == 2)
		all->ifract = 0;
	refresh_window(all);
}

int		key_func(int keycode, t_all *all)
{
	if (keycode >= 123 && keycode <= 126)
		move(all, keycode);
	if (keycode == 53)
		quit(all);
	if (keycode == 15)
		reinit(all);
	if (keycode == 49)
		change_fract(all);
	//printf("keycode = %i\n", keycode);
	return (0);
}
