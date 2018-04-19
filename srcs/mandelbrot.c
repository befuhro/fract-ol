/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 14:54:55 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(t_comp *c, t_comp *z, t_comp *sqrz)
{
	z->im = (z->re + z->im) * (z->re + z->im) - sqrz->re - sqrz->im;
	z->im += c->im;
	z->re = sqrz->re - sqrz->im + c->re;
	sqrz->re = z->re * z->re;
	sqrz->im = z->im * z->im;
}

void	mandelbrot1(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = -1;
	while (++f.y < 90)
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

void	mandelbrot2(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 89;
	while (++f.y < 180)
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

void	mandelbrot3(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 179;
	while (++f.y < 270)
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

void	mandelbrot4(void *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 269;
	while (++f.y < 360)
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
