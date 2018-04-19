/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot_next.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 18:27:27 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 16:08:17 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot5(void *ptr)
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
			conv(f.x, f.y, &f.c, f);
			f.z.re = 0;
			f.z.im = 0;
			f.sqrz.re = 0;
			f.sqrz.im = 0;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_mandelbrot(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->t_ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	mandelbrot6(void *ptr)
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
			conv(f.x, f.y, &f.c, f);
			f.z.re = 0;
			f.z.im = 0;
			f.sqrz.re = 0;
			f.sqrz.im = 0;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_mandelbrot(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->t_ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	mandelbrot7(void *ptr)
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
			conv(f.x, f.y, &f.c, f);
			f.z.re = 0;
			f.z.im = 0;
			f.sqrz.re = 0;
			f.sqrz.im = 0;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_mandelbrot(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->t_ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	mandelbrot8(void *ptr)
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
			conv(f.x, f.y, &f.c, f);
			f.z.re = 0;
			f.z.im = 0;
			f.sqrz.re = 0;
			f.sqrz.im = 0;
			while (++f.count <= ITMAX && f.sqrz.re + f.sqrz.im <= 4)
				calc_mandelbrot(&f.c, &f.z, &f.sqrz);
			if (f.count <= ITMAX)
				ref->t_ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}

void	manage_mandelbrot(t_all *all)
{
	pthread_t	block[8];

	pthread_create(&block[0], NULL, (void*)mandelbrot1, (void*)all);
	pthread_create(&block[1], NULL, (void*)mandelbrot2, (void*)all);
	pthread_create(&block[2], NULL, (void*)mandelbrot3, (void*)all);
	pthread_create(&block[3], NULL, (void*)mandelbrot4, (void*)all);
	pthread_create(&block[4], NULL, (void*)mandelbrot5, (void*)all);
	pthread_create(&block[5], NULL, (void*)mandelbrot6, (void*)all);
	pthread_create(&block[6], NULL, (void*)mandelbrot7, (void*)all);
	pthread_create(&block[7], NULL, (void*)mandelbrot8, (void*)all);
	pthread_join(block[0], NULL);
	pthread_join(block[1], NULL);
	pthread_join(block[2], NULL);
	pthread_join(block[3], NULL);
	pthread_join(block[4], NULL);
	pthread_join(block[5], NULL);
	pthread_join(block[6], NULL);
	pthread_join(block[7], NULL);
}
