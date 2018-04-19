/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_input.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 17:07:34 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 15:00:52 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	quit(t_all *all)
{
	mlx_destroy_image(all->init, all->image_ptr);
	mlx_destroy_window(all->init, all->win);
	free(all->ptrcolor);
	free(all->ptrfract);
	free(all->fract);
	exit(0);
}

void	move(t_all *all, int keycode)
{
	double	ratio;

	ratio = (all->fract->maxx - all->fract->minx) * (100 / 5.2);
	if (keycode == 124)
	{
		all->fract->minx += ratio / 100;
		all->fract->maxx += ratio / 100;
	}
	else if (keycode == 123)
	{
		all->fract->minx -= ratio / 100;
		all->fract->maxx -= ratio / 100;
	}
	else if (keycode == 126)
	{
		all->fract->miny -= ratio / 100;
		all->fract->maxy -= ratio / 100;
	}
	else if (keycode == 125)
	{
		all->fract->miny += ratio / 100;
		all->fract->maxy += ratio / 100;
	}
}

void	reinit(t_all *all)
{
	all->fract->minx = -2;
	all->fract->maxx = 2;
	all->fract->miny = -1.25;
	all->fract->maxy = 1.25;
}

void	change_fract(t_all *all)
{
	all->ifract++;
	if (all->ifract == 2)
		all->ifract = 0;
}

int		key_func(int keycode, t_all *all)
{
	if (keycode >= 123 && keycode <= 126)
		move(all, keycode);
	else if (keycode == 53)
		quit(all);
	else if (keycode == 15)
		reinit(all);
	else if (keycode == 49)
		change_fract(all);
	else if (keycode == 37)
	{
		if (all->fract->pause == 0)
			all->fract->pause = 1;
		else
			all->fract->pause = 0;
	}
	refresh_window(all);
	return (0);
}
