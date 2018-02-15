/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 20:13:21 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 16:29:46 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	zoom(t_all *all, int x, int y)
{	
	double	ratio;

	ratio = (all->fract->maxX - all->fract->minX) * (100 / 5.2);
	
	all->fract->minX += (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->maxX += (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->minY += (y - (HEIGHT / 2)) * (ratio / 238000);
	all->fract->maxY += (y - (HEIGHT / 2)) * (ratio / 238000);

	all->fract->minX += ratio / (1000 / 2.4);
	all->fract->maxX -= ratio / (1000 / 2.4);
	all->fract->minY += ratio / (1000 / 1.5);
	all->fract->maxY -= ratio / (1000 / 1.5);
}

void	unzoom(t_all *all, int x, int y)
{	
	double	ratio;

	ratio = (all->fract->maxX - all->fract->minX) * (100 / 5.2);
	
	all->fract->minX -= (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->maxX -= (x - (WIDTH / 2)) * (ratio / 284150);
	all->fract->minY -= (y - (HEIGHT / 2)) * (ratio / 238000);
	all->fract->maxY -= (y - (HEIGHT / 2)) * (ratio / 238000);

	all->fract->minX -= ratio / (1000 / 2.4);
	all->fract->maxX += ratio / (1000 / 2.4);
	all->fract->minY -= ratio / (1000 / 1.5);
	all->fract->maxY += ratio / (1000 / 1.5);
}
