/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:02:57 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 05:30:42 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void	refresh_window(t_all *all)
{
	mlx_clear_window(all->init, all->win);
	mandelbrot(all->image_string, all->ptrColor[all->indexColor]);
	mlx_put_image_to_window(all->image_string, all->win, all->image_ptr, 0, 0);
}

void	quit(t_all *all)
{
	mlx_destroy_image(all->init, all->image_ptr);
	mlx_clear_window(all->init, all->win);
	exit(0);
}

int 	mouse_func(int mousecode, t_all *all)
{
//	printf("%i\n", mousecode);
	if (mousecode == 49)
	{
		all->indexColor++;
		if (all->indexColor == 3)
			all->indexColor = 0;
		refresh_window(all);
	}
	if (mousecode == 53)
		quit(all);
	return (0);
}
