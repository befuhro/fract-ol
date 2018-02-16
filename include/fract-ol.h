/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fract-ol.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:08:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:31:54 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <fcntl.h>
# include "mlx.h"
# include <stdlib.h>
# include "libft.h"
# include <math.h>
# include <pthread.h>
# define	WIDTH	1366
# define 	HEIGHT	720

typedef	void	(*ptr2func)(char *, double, double, double);

typedef struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_color;

typedef	struct	s_fract
{
	double	minX;
	double	maxX;
	double	minY;
	double	maxY;
	double	x;
	double	y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	z_rsqr;
	double	z_isqr;
	double	i;
	double	z;
	int		count;
	int		y_begin;
	int		y_end;
}			t_fract;

typedef struct	s_all
{
	void			*init;
	void			*win;
	void			*image_ptr;
	char			*im_s;
	ptr2func  		*ptrColor;
	int				iColor;
	t_fract			*fract;
	int				index_thread;
}				t_all;

void	calc_mandelbrot(t_fract *fract);
void	manage_mandelbrot(t_all *all);
void    first_color(char *image_string, double count, double x, double y);
void    second_color(char *image_string, double count, double x, double y);
void    third_color(char *image_string, double count, double x, double y);
void	fill_pixel(char *image_string, int x, int y, t_color color);
int		mouse_func(int mousecode, int x, int y, t_all *all);
int		key_func(int keycode, t_all *all);
void	refresh_window(t_all *all);
void	zoom(t_all *all, int x, int y);
void	unzoom(t_all *all, int x, int y);
ptr2func	*makeTab(void);
void	copy_struct(t_fract *origin, t_fract *copy);
double	ft_condi(double min, double max);
void    mandelbrot5(void *ptr);
void    mandelbrot6(void *ptr);
void    mandelbrot7(void *ptr);
void    mandelbrot8(void *ptr);

#endif
