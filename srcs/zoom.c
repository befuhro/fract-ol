/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 20:13:21 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 15:00:50 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_all *all, int x, int y)
{
	double	ratio;

	ratio = (all->fract->maxx - all->fract->minx) * (100 / 5.2);
	all->fract->minx += (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->maxx += (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->miny += (y - (HEIGHT / 2)) * (ratio / 237800);
	all->fract->maxy += (y - (HEIGHT / 2)) * (ratio / 237800);
	all->fract->minx += ratio / (1000 / 2.4);
	all->fract->maxx -= ratio / (1000 / 2.4);
	all->fract->miny += ratio / (1000 / 1.5);
	all->fract->maxy -= ratio / (1000 / 1.5);
}

void	unzoom(t_all *all, int x, int y)
{
	double	ratio;

	ratio = (all->fract->maxx - all->fract->minx) * (100 / 5.2);
	all->fract->minx -= (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->maxx -= (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->miny -= (y - (HEIGHT / 2)) * (ratio / 238000);
	all->fract->maxy -= (y - (HEIGHT / 2)) * (ratio / 238000);
	all->fract->minx -= ratio / (1000 / 2.4);
	all->fract->maxx += ratio / (1000 / 2.4);
	all->fract->miny -= ratio / (1000 / 1.5);
	all->fract->maxy += ratio / (1000 / 1.5);
}
