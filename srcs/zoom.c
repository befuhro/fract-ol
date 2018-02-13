/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 20:13:21 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 00:23:46 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void	zoom(t_all *all, int x, int y)
{	
	double	ratio;

	ratio = (all->fract->maxX - all->fract->minX) * (100 / 5.2);
	
	
	all->fract->minX += (x - 540) * (ratio / 100000);
	all->fract->maxX +=  (x - 540) * (ratio / 100000);

	all->fract->minY +=  (y - 300) * (ratio / 100000);
	all->fract->maxY +=  (y - 300) * (ratio / 100000);

	all->fract->minX *= 0.95;
	all->fract->maxX *= 0.95;
	all->fract->minY *= 0.95;
	all->fract->maxY *= 0.95;
}

void	unzoom(t_all *all, int x, int y)
{	
	double	ratio;

	ratio = (all->fract->maxX - all->fract->minX) * (100 / 5.2);
	
	
	all->fract->minX -= (x - 540) * (ratio / 100000);
	all->fract->maxX -=  (x - 540) * (ratio / 100000);

	all->fract->minY -=  (y - 300) * (ratio / 100000);
	all->fract->maxY -=  (y - 300) * (ratio / 100000);

	all->fract->minX *= 1.05;
	all->fract->maxX *= 1.05;
	all->fract->minY *= 1.05;
	all->fract->maxY *= 1.05;








}
