/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:02:57 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 23:19:50 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void	refresh_window(t_all *all)
{
	if (all->iColor == 3)
		all->iColor = 0;
	if (all->iColor == -1)
		all->iColor = 2;
	mlx_clear_window(all->init, all->win);
	manage_mandelbrot(all);
	mlx_put_image_to_window(all->im_s, all->win, all->image_ptr, 0, 0);
}

int 	mouse_func(int mousecode, int x, int y, t_all *all)
{
//	printf("%i\n%i\n%i\n", mousecode, x, y);
	if (mousecode == 1)
		all->iColor++;
	if (mousecode == 2)
		all->iColor--;
	if (mousecode == 4)
		zoom(all, x, y);
	if (mousecode == 5)
		unzoom(all, x, y);
	refresh_window(all);
	return (0);
}
