/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia_next.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 15:04:33 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 15:21:12 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	julia5(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 359;
	while (++f.y < 450)
	{
		f.x = -1;
		while (++f.x < WIDTH)
		{
			f.count = -1;
			f.c.re = f.mouse.re;
			f.c.im = f.mouse.im;
			conv(f.x, f.y, &f.z, f);	
			f.sqrz.re = f.z.re * f.z.re;
			f.sqrz.im = f.z.im * f.z.im;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_julia(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	julia6(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 449;
	while (++f.y < 540)
	{
		f.x = -1;
		while (++f.x < WIDTH)
		{
			f.count = -1;
			f.c.re = f.mouse.re;
			f.c.im = f.mouse.im;
			conv(f.x, f.y, &f.z, f);	
			f.sqrz.re = f.z.re * f.z.re;
			f.sqrz.im = f.z.im * f.z.im;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_julia(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	julia7(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 539;
	while (++f.y < 630)
	{
		f.x = -1;
		while (++f.x < WIDTH)
		{
			f.count = -1;
			f.c.re = f.mouse.re;
			f.c.im = f.mouse.im;
			conv(f.x, f.y, &f.z, f);	
			f.sqrz.re = f.z.re * f.z.re;
			f.sqrz.im = f.z.im * f.z.im;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_julia(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	julia8(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 629;
	while (++f.y < 720)
	{
		f.x = -1;
		while (++f.x < WIDTH)
		{
			f.count = -1;
			f.c.re = f.mouse.re;
			f.c.im = f.mouse.im;
			conv(f.x, f.y, &f.z, f);	
			f.sqrz.re = f.z.re * f.z.re;
			f.sqrz.im = f.z.im * f.z.im;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_julia(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	manage_julia(t_all *all)
{
	pthread_t	block[8];

	pthread_create(&block[0], NULL, (void*)julia1, (void*)all);
	pthread_create(&block[1], NULL, (void*)julia2, (void*)all);
	pthread_create(&block[2], NULL, (void*)julia3, (void*)all);
	pthread_create(&block[3], NULL, (void*)julia4, (void*)all);
	pthread_create(&block[4], NULL, (void*)julia5, (void*)all);
	pthread_create(&block[5], NULL, (void*)julia6, (void*)all);
	pthread_create(&block[6], NULL, (void*)julia7, (void*)all);
	pthread_create(&block[7], NULL, (void*)julia8, (void*)all);
	pthread_join(block[0], NULL);
	pthread_join(block[1], NULL);
	pthread_join(block[2], NULL);
	pthread_join(block[3], NULL);
	pthread_join(block[4], NULL);
	pthread_join(block[5], NULL);
	pthread_join(block[6], NULL);
	pthread_join(block[7], NULL);
}
