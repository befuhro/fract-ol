/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:20 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 16:09:56 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	init_all(t_all *all)
{
	int		bpp;
	int		s_l;
	int		endian;

	all->init = mlx_init();
	all->win = mlx_new_window(all->init, WIDTH, HEIGHT, "fract-ol");
	all->image_ptr = mlx_new_image(all->init, WIDTH, HEIGHT);
	all->im_s = mlx_get_data_addr(all->image_ptr, &bpp, &s_l, &endian);
	all->icolor = 0;
	all->fract = (t_fract*)malloc(sizeof(t_fract));
}

void	gestion(t_all *all, char *s)
{
	if (!ft_strcmp(s, "mandelbrot"))
		all->ifract = 0;
	else if (!ft_strcmp(s, "julia"))
		all->ifract = 1;
	else if (!ft_strcmp(s, "burningship"))
		all->ifract = 2;
	all->fract->minx = -2;
	all->fract->maxx = 2;
	all->fract->miny = -1.25;
	all->fract->maxy = 1.25;
	all->t_ptrcolor = initcolor();
	all->t_ptrfract = initfract();
	all->fract->pause = 0;
	mlx_mouse_hook(all->win, mouse_func, all);
	mlx_key_hook(all->win, key_func, all);
	if (all->ifract == 1 && all->fract->pause == 0)
		mlx_hook(all->win, 6, 1L << 6, refresh_julia, all);
	mlx_put_image_to_window(all->im_s, all->win, all->image_ptr, 0, 0);
	refresh_window(all);
	mlx_loop(all->init);
}

int		main(int ac, char **av)
{
	t_all	*all;

	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "julia")
		|| !ft_strcmp(av[1], "burningship")))
	{
		all = (t_all *)malloc(sizeof(t_all));
		init_all(all);
		gestion(all, av[1]);
	}
	else
		ft_putendl("fract-ol usage:");
	return (0);
}
