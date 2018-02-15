/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 19:54:32 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void    *mandelbrot1(void *ptr)
{
	t_fract	fract;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&fract, ref->fract, sizeof(t_fract));
	fract.y = -1;
	while (++fract.y < 180)
	{
		fract.x = -1;
		while (++fract.x < WIDTH)
		{
			fract.c_r = fract.minX + (fract.maxX - fract.minX) / WIDTH * fract.x;
			fract.c_i = fract.minY + (fract.maxY - fract.minY) / HEIGHT * fract.y;
			fract.z_r = 0;
			fract.z_i = 0;
			fract.count = -1;
			fract.z_rsqr = 0;
			fract.z_isqr = 0;
			while (++fract.count <= 35 && fract.z_rsqr + fract.z_isqr <= 4)
			{
				fract.z_i = (fract.z_r + fract.z_i) * (fract.z_r + fract.z_i) - fract.z_rsqr - fract.z_isqr;
				fract.z_i += fract.c_i;
				fract.z_r = fract.z_rsqr - fract.z_isqr + fract.c_r;
				fract.z_rsqr = fract.z_r * fract.z_r;
				fract.z_isqr = fract.z_i * fract.z_i;
				ref->ptrColor[ref->indexColor](ref->image_string, fract.count, fract.x, fract.y);
			}
		}
	}
	return (0);
}

void    *mandelbrot2(void *ptr)
{
	t_fract	fract;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&fract, ref->fract, sizeof(t_fract));
	fract.y = 179;
	while (++fract.y < 360)
	{
		fract.x = -1;
		while (++fract.x < WIDTH)
		{
			fract.c_r = fract.minX + (fract.maxX - fract.minX) / WIDTH * fract.x;
			fract.c_i = fract.minY + (fract.maxY - fract.minY) / HEIGHT * fract.y;
			fract.z_r = 0;
			fract.z_i = 0;
			fract.count = -1;
			fract.z_rsqr = 0;
			fract.z_isqr = 0;
			while (++fract.count <= 35 && fract.z_rsqr + fract.z_isqr <= 4)
			{
				fract.z_i = (fract.z_r + fract.z_i) * (fract.z_r + fract.z_i) - fract.z_rsqr - fract.z_isqr;
				fract.z_i += fract.c_i;
				fract.z_r = fract.z_rsqr - fract.z_isqr + fract.c_r;
				fract.z_rsqr = fract.z_r * fract.z_r;
				fract.z_isqr = fract.z_i * fract.z_i;
				ref->ptrColor[ref->indexColor](ref->image_string, fract.count, fract.x, fract.y);
			}
		}
	}
	return (0);
}

void    *mandelbrot3(void *ptr)
{
	t_fract	fract;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&fract, ref->fract, sizeof(t_fract));
	fract.y = 359;
	while (++fract.y < 540)
	{
		fract.x = -1;
		while (++fract.x < WIDTH)
		{
			fract.c_r = fract.minX + (fract.maxX - fract.minX) / WIDTH * fract.x;
			fract.c_i = fract.minY + (fract.maxY - fract.minY) / HEIGHT * fract.y;
			fract.z_r = 0;
			fract.z_i = 0;
			fract.count = -1;
			fract.z_rsqr = 0;
			fract.z_isqr = 0;
			while (++fract.count <= 35 && fract.z_rsqr + fract.z_isqr <= 4)
			{
				fract.z_i = (fract.z_r + fract.z_i) * (fract.z_r + fract.z_i) - fract.z_rsqr - fract.z_isqr;
				fract.z_i += fract.c_i;
				fract.z_r = fract.z_rsqr - fract.z_isqr + fract.c_r;
				fract.z_rsqr = fract.z_r * fract.z_r;
				fract.z_isqr = fract.z_i * fract.z_i;
				ref->ptrColor[ref->indexColor](ref->image_string, fract.count, fract.x, fract.y);
			}
		}
	}
	return (0);
}

void    *mandelbrot4(void *ptr)
{
	t_fract	fract;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&fract, ref->fract, sizeof(t_fract));
	fract.y = 539;
	while (++fract.y < 720)
	{
		fract.x = -1;
		while (++fract.x < WIDTH)
		{
			fract.count = -1;
			fract.c_r = fract.minX + (fract.maxX - fract.minX) / WIDTH * fract.x;
			fract.c_i = fract.minY + (fract.maxY - fract.minY) / HEIGHT * fract.y;
			fract.z_r = 0;
			fract.z_i = 0;
			fract.z_rsqr = 0;
			fract.z_isqr = 0;
			while (++fract.count <= 35 && fract.z_rsqr + fract.z_isqr <= 4)
			{
				fract.z_i = (fract.z_r + fract.z_i) * (fract.z_r + fract.z_i) - fract.z_rsqr - fract.z_isqr;
				fract.z_i += fract.c_i;
				fract.z_r = fract.z_rsqr - fract.z_isqr + fract.c_r;
				fract.z_rsqr = fract.z_r * fract.z_r;
				fract.z_isqr = fract.z_i * fract.z_i;
				ref->ptrColor[ref->indexColor](ref->image_string, fract.count, fract.x, fract.y);
			}
		}
	}
	return (0);
}

void	manage_mandelbrot(t_all *all)
{
	pthread_t 	thread1;
	pthread_t 	thread2;
	pthread_t 	thread3;
	pthread_t 	thread4;

	pthread_create(&thread1, NULL, mandelbrot1, (void*)all);
	pthread_create(&thread2, NULL, mandelbrot2, (void*)all);
	pthread_create(&thread3, NULL, mandelbrot3, (void*)all);
	pthread_create(&thread4, NULL, mandelbrot4, (void*)all);
	pthread_join(thread1, NULL);	
	pthread_join(thread2, NULL);	
	pthread_join(thread3, NULL);	
	pthread_join(thread4, NULL);
}
