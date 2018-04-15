#include "fract-ol.h"

// c = plan complexe (mouse position)
// z = plan complexe (pixel position)

void	calc_julia(t_comp *c, t_comp *z, t_comp *sqrz)
{
	z->im = (z->re + z->im) * (z->re + z->im) - sqrz->re - sqrz->im;
	z->im += c->im;
	z->re = sqrz->re - sqrz->im + c->re;
	sqrz->re = z->re * z->re;
	sqrz->im = z->im * z->im;
}

void	julia(t_all *ptr)
{
	t_fract	f;
	t_all	*ref;

	ref = ptr;
	ft_memcpy(&f, ref->fract, sizeof(t_fract));
	f.y = 0;
	while (++f.y < HEIGHT)
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
	pthread_t	block[1];
	pthread_create(&block[0], NULL, (void*)julia, (void*)all);
	pthread_join(block[0], NULL);
}
