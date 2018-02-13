/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 00:24:27 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void    *mandelbrot(void *ptr)
{
	t_fract	fract;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&fract, ref->fract, sizeof(t_fract));
	fract.y = ref->fract->y_begin;
	while (++fract.y < ref->fract->y_end)
	{
		fract.x = -1;
		while (++fract.x < 1080)
		{
			fract.rC = fract.minX + (fract.maxX - fract.minX) / 1080 * fract.x;
			fract.iC = fract.minY + (fract.maxY - fract.minY) / 700 * fract.y;
			fract.rZ = 0;
			fract.iZ = 0;
			fract.count = -1;
			while (++fract.count <= 50 && fract.rZ * fract.rZ + fract.iZ * fract.iZ <= 4)
			{
				fract.I = fract.iZ;
				fract.iZ = (fract.rZ + fract.rZ) * fract.iZ + fract.iC;
				fract.rZ = fract.rZ * fract.rZ - fract.I * fract.I + fract.rC;
				ref->ptrColor[ref->indexColor](ref->image_string, fract.count, fract.x, fract.y);
			}
		}
	}
	return (0);
}

void	manage_mandelbrot(t_all *all)
{
	t_thread	block;

	all->fract->y_begin = -1;
	all->fract->y_end = 140;
	pthread_create(&block.thread1, NULL, mandelbrot, (void*)all);
	all->fract->y_end += 140;
	pthread_create(&block.thread2, NULL, mandelbrot, (void*)all);
	all->fract->y_end += 140;
	pthread_create(&block.thread3, NULL, mandelbrot, (void*)all);
	all->fract->y_end += 140;
	pthread_create(&block.thread4, NULL, mandelbrot, (void*)all);
	all->fract->y_end += 140;
	pthread_create(&block.thread5, NULL, mandelbrot, (void*)all);
	pthread_join(block.thread1, NULL);	
	pthread_join(block.thread2, NULL);	
	pthread_join(block.thread3, NULL);	
	pthread_join(block.thread4, NULL);	
	pthread_join(block.thread5, NULL);	
}
