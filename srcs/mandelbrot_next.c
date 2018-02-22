/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot_next.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 18:27:27 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 23:37:19 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	calc_mandelbrot(t_fract *f)
{
	f->z_i = (f->z_r + f->z_i) * (f->z_r + f->z_i) - f->z_rsqr - f->z_isqr;
	f->z_i += f->c_i;
	f->z_r = f->z_rsqr - f->z_isqr + f->c_r;
	f->z_rsqr = f->z_r * f->z_r;
	f->z_isqr = f->z_i * f->z_i;
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
			f.c_r = f.minX + (f.maxX - f.minX) / WIDTH * f.x;
			f.c_i = f.minY + (f.maxY - f.minY) / HEIGHT * f.y;
			f.z_r = 0;
			f.z_i = 0;
			f.count = -1;
			f.z_rsqr = 0;
			f.z_isqr = 0;
			while (++f.count <= 100 && f.z_rsqr + f.z_isqr <= 4)
				calc_mandelbrot(&f);
			if (f.count <= 100)
				ref->ptrColor[ref->iColor](ref->im_s, f.count, f.x, f.y);
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
			f.c_r = f.minX + (f.maxX - f.minX) / WIDTH * f.x;
			f.c_i = f.minY + (f.maxY - f.minY) / HEIGHT * f.y;
			f.z_r = 0;
			f.z_i = 0;
			f.count = -1;
			f.z_rsqr = 0;
			f.z_isqr = 0;
			while (++f.count <= 100 && f.z_rsqr + f.z_isqr <= 4)
				calc_mandelbrot(&f);
			if (f.count <= 100)
				ref->ptrColor[ref->iColor](ref->im_s, f.count, f.x, f.y);
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
			f.c_r = f.minX + (f.maxX - f.minX) / WIDTH * f.x;
			f.c_i = f.minY + (f.maxY - f.minY) / HEIGHT * f.y;
			f.z_r = 0;
			f.z_i = 0;
			f.count = -1;
			f.z_rsqr = 0;
			f.z_isqr = 0;
			while (++f.count <= 100 && f.z_rsqr + f.z_isqr <= 4)
				calc_mandelbrot(&f);
			if (f.count <= 100)
				ref->ptrColor[ref->iColor](ref->im_s, f.count, f.x, f.y);
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
			f.c_r = f.minX + (f.maxX - f.minX) / WIDTH * f.x;
			f.c_i = f.minY + (f.maxY - f.minY) / HEIGHT * f.y;
			f.z_r = 0;
			f.z_i = 0;
			f.z_rsqr = 0;
			f.z_isqr = 0;
			while (++f.count <= 100 && f.z_rsqr + f.z_isqr <= 4)
				calc_mandelbrot(&f);
			if (f.count <= 100)
				ref->ptrColor[ref->iColor](ref->im_s, f.count, f.x, f.y);
		}
	}
}
