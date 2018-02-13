/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_input.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 17:07:34 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 17:15:07 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void    quit(t_all *all)
{
	mlx_destroy_image(all->init, all->image_ptr);
	mlx_clear_window(all->init, all->win);
	exit(0);
}

int		key_func(int keycode, t_all *all)
{
	if (keycode == 53)
		quit(all);
	return (0);
}
