/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:02:57 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 14:55:13 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	refresh_window(t_all *all)
{
	int bpp;
	int s_l;
	int endian;

	if (all->icolor == 3)
		all->icolor = 0;
	if (all->icolor == -1)
		all->icolor = 2;
	mlx_clear_window(all->init, all->win);
	mlx_destroy_image(all->init, all->image_ptr);
	all->image_ptr = mlx_new_image(all->init, WIDTH, HEIGHT);
	all->im_s = mlx_get_data_addr(all->image_ptr, &bpp, &s_l, &endian);
	all->ptrfract[all->ifract](all);
	mlx_put_image_to_window(all->im_s, all->win, all->image_ptr, 0, 0);
}

int		refresh_julia(int x, int y, t_all *all)
{
	if (all->fract->pause == 0)
	{
		conv(x, y, &all->fract->mouse, *all->fract);
		refresh_window(all);
	}
	return (0);
}

int		mouse_func(int mousecode, int x, int y, t_all *all)
{
	if (mousecode == 1)
		all->icolor++;
	else if (mousecode == 2)
		all->icolor--;
	else if (mousecode == 4)
		zoom(all, x, y);
	else if (mousecode == 5)
		unzoom(all, x, y);
	refresh_window(all);
	return (0);
}
