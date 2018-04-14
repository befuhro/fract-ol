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
			conv(f.x, f.y, &f.c, f);
//			f.c.re = -0.038088;
//			f.c.im = 0.97;


			f.z.re = 0;
			f.z.im = 0;
//			conv(f.x, f.y, &f.z, f);	

			f.sqrz.re = 0;
			f.sqrz.im = 0;
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
