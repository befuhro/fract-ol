/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 15:00:25 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 15:19:24 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	calc_julia(t_comp *c, t_comp *z, t_comp *sqrz)
{
	z->im = (z->re + z->im) * (z->re + z->im) - sqrz->re - sqrz->im;
	z->im += c->im;
	z->re = sqrz->re - sqrz->im + c->re;
	sqrz->re = z->re * z->re;
	sqrz->im = z->im * z->im;
}

void	julia1(void *ptr)
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

void	julia2(void *ptr)
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

void	julia3(void *ptr)
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

void	julia4(void *ptr)
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
