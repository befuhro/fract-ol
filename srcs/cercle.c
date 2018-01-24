/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cercle.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 17:43:23 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 21:51:13 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract'ol.h"

void	cercle(t_whole *whole, int x, int y, int r)
{
	t_coord point;
	int d;

	point.x = 0;
	point.y = r;
	d = r - 1;
	while (point.y >= point.x)
	{
		ft_putendl("Ya");
		mlx_pixel_put(whole->init, whole->win, x + point.x, y + point.y, 16777215);
		mlx_pixel_put(whole->init, whole->win, x + point.y, y + point.x, 16777215);
		mlx_pixel_put(whole->init, whole->win, x - point.x, y + point.y, 16777215);
		mlx_pixel_put(whole->init, whole->win, x - point.y, y + point.x, 16777215);
		mlx_pixel_put(whole->init, whole->win, x + point.x, y - point.y, 16777215);
		mlx_pixel_put(whole->init, whole->win, x + point.y, y - point.x, 16777215);
		mlx_pixel_put(whole->init, whole->win, x - point.x, y - point.y, 16777215);
		mlx_pixel_put(whole->init, whole->win, x - point.y, y - point.x, 16777215);
		if (d >= 2 * point.x)
		{
			d = d - 2 * point.x + 1;
			point.x++;
		}
		else if (d < 2 * (r - point.y))
		{
			d = d + 2 * point.y - 1;
			point.y--;
		}
		else
		{
			d = d + 2 * (point.y - point.x - 1);
			point.y--;
			point.x++;
		}
	}	
}
