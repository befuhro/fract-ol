/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_input.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 17:07:34 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 13:39:53 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		quit(t_all *all)
{
	mlx_destroy_image(all->init, all->image_ptr);
	mlx_destroy_window(all->init, all->win);
	free(all->init);
	free(all->t_ptrcolor);
	free(all->t_ptrfract);
	free(all->fract);
	exit(0);
	return (0);
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

int		key_func(int keycode, t_all *all)
{
	if (keycode >= 123 && keycode <= 126)
		move(all, keycode);
	else if (keycode == 53)
		quit(all);
	else if (keycode == 15)
		reinit(all);
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
