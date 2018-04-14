/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot_next.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 18:27:27 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 23:27:18 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	calc_mandelbrot(t_comp *c, t_comp *z, t_comp *sqrz)
{
	z->im = (z->re + z->im) * (z->re + z->im) - sqrz->re - sqrz->im;
	z->im += c->im;
	z->re = sqrz->re - sqrz->im + c->re;
	sqrz->re = z->re * z->re;
	sqrz->im = z->im * z->im;
}

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
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
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
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
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
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
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
				ref->ptrcolor[ref->icolor](ref->im_s, f.count, f.x, f.y);
		}
	}
}
