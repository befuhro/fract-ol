/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:20 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 18:02:59 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

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
		all->ifract  = 1;
	all->fract->minX = -2;
	all->fract->maxX = 2;
	all->fract->minY = -1.25;
	all->fract->maxY = 1.25;
	all->ptrcolor = initcolor();
	all->ptrfract = initfract();
	mlx_put_image_to_window(all->im_s, all->win, all->image_ptr, 0, 0);
	mlx_mouse_hook(all->win, mouse_func, all);
	mlx_key_hook(all->win, key_func, all);
	mlx_loop(all->init);
}


int	main(int ac, char **av)
{
	t_all	*all;

	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "julia")))
	{
		all = (t_all *) malloc(sizeof(t_all));
		init_all(all);
		gestion(all, av[1]);
	}
	else
		ft_putendl("fract-ol usage:");
	return (0);
}
