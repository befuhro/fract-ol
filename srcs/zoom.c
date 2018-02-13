/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 20:13:21 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 01:35:34 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void	zoom(t_all *all, int x, int y)
{	
	if (x > 540)
	{
		all->fract->minX += 0.05;
		all->fract->maxX += 0.05;
	}
	else
	{
		all->fract->minX -= 0.05;
		all->fract->maxX -= 0.05;
	}
	if (y > 300)
	{
		all->fract->minY += 0.05;
		all->fract->maxY += 0.05;
	}
	else
	{
		all->fract->minY -= 0.05;
		all->fract->maxY -= 0.05;
	}
	all->fract->minX /= 1.05;
	all->fract->maxX /= 1.05;
	all->fract->minY /= 1.05;
	all->fract->maxY /= 1.05;
}

void	unzoom(t_all *all, int x, int y)
{	
	if (x > 540)
	{
		all->fract->minX += 0.05;
		all->fract->maxX += 0.05;
	}
	else
	{
		all->fract->minX -= 0.05;
		all->fract->maxX -= 0.05;
	}
	if (y > 300)
	{
		all->fract->minY += 0.05;
		all->fract->maxY += 0.05;
	}
	else
	{
		all->fract->minY -= 0.05;
		all->fract->maxY -= 0.05;
	}
	all->fract->minX *= 1.05;
	all->fract->maxX *= 1.05;
	all->fract->minY *= 1.05;
	all->fract->maxY *= 1.05;
}
