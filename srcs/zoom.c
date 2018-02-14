/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 20:13:21 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 23:31:47 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void	zoom(t_all *all, int x, int y)
{	
	double	ratio;

	ratio = (all->fract->maxX - all->fract->minX) * (100 / 5.2);
		(void)x;
	(void)y;


	
	all->fract->minX += (x - (WIDTH / 2)) * (ratio / 260000);
	all->fract->maxX +=  (x - (WIDTH / 2)) * (ratio / 260000);

	all->fract->minY +=  (y - (HEIGHT / 2)) * (ratio / 260000);
	all->fract->maxY +=  (y - (HEIGHT / 2)) * (ratio / 260000);

	all->fract->minX += ratio / (1000 / 2.4);
	all->fract->maxX -= ratio / (1000 / 2.4);
	all->fract->minY += ratio / (1000 / 1.5);
	all->fract->maxY -= ratio / (1000 / 1.5);




	printf("minX\t\tmaxX\t\tminY\t\tmaxY\n___________________________________________\n%f\t%f\t%f\t%f\n\n\n\n",
		all->fract->minX,  all->fract->maxX,  all->fract->minY, all->fract->maxY);


}

void	unzoom(t_all *all, int x, int y)
{	
	double	ratio;

	ratio = (all->fract->maxX - all->fract->minX) * (100 / 5.2);
	
	(void)x;
	(void)y;

//	all->fract->minX -= (x - (WIDTH / 2)) * (ratio / 100000);
//	all->fract->maxX -=  (x - (WIDTH / 2)) * (ratio / 100000);

//	all->fract->minY -=  (y - (HEIGHT / 2)) * (ratio / 100000);
//	all->fract->maxY -=  (y - (HEIGHT / 2)) * (ratio / 100000);

	all->fract->minX *= 1.05;
	all->fract->maxX *= 1.05;
	all->fract->minY *= 1.05;
	all->fract->maxY *= 1.05;
}
