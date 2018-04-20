/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:20 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 12:41:49 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		init_all(t_all *all)
{
	int		bpp;
	int		s_l;
	int		endian;

	if ((all->t_ptrcolor = initcolor()) == NULL)
		return (1);
	if ((all->t_ptrfract = initfract()) == NULL)
		return (1);
	if ((all->init = mlx_init()) == NULL)
		return (1);
	if ((all->win = mlx_new_window(all->init, WIDTH, HEIGHT, "fract-ol"))\
		== NULL)
		return (1);
	if ((all->image_ptr = mlx_new_image(all->init, WIDTH, HEIGHT)) == NULL)
		return (1);
	if ((all->im_s = mlx_get_data_addr(all->image_ptr, &bpp, &s_l, &endian))\
		== NULL)
		return (1);
	if ((all->fract = (t_fract*)malloc(sizeof(t_fract))) == NULL)
		return (1);
	return (0);
}

int		gestion(t_all *all, char *s)
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
	all->fract->pause = 0;
	mlx_mouse_hook(all->win, mouse_func, all);
	mlx_key_hook(all->win, key_func, all);
	if (all->ifract == 1 && all->fract->pause == 0)
		mlx_hook(all->win, 6, 1L << 6, refresh_julia, all);
	mlx_hook(all->win, 17, 1L << 17, quit, all);
	mlx_put_image_to_window(all->im_s, all->win, all->image_ptr, 0, 0);
	refresh_window(all);
	mlx_loop(all->init);
	return (0);
}

int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "julia")
		|| !ft_strcmp(av[1], "burningship")))
	{
		if (!(all = (t_all *)malloc(sizeof(t_all))))
			return (1);
		if (init_all(all) == 1)
			return (1);
		gestion(all, av[1]);
	}
	else
		ft_putendl("fract-ol usage:");
	return (0);
}
