/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fract-ol.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:08:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 23:27:01 by befuhro     ###    #+. /#+    ###.fr     */
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
# define	ITMAX	100

typedef struct 	s_all t_all;
typedef	void	(*ptrcolor)(char *, double, double, double);
typedef	void	(*ptrfract)(t_all *all);

typedef struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_color;

typedef	struct	s_comp
{
	double	re;
	double	im;
}				t_comp;

typedef	struct	s_fract
{
	double	minX;
	double	maxX;
	double	minY;
	double	maxY;
	double	x;
	double	y;

	t_comp	c;
	t_comp	z;
	t_comp	sqrz;
	t_comp	mouse;
	int		count;
}			t_fract;

typedef struct	s_all
{
	void			*init;
	void			*win;
	void			*image_ptr;
	char			*im_s;
	ptrcolor  		*ptrcolor;
	ptrfract 		*ptrfract;
	int				icolor;
	int 			ifract;
	t_fract			*fract;
}				t_all;

void		calc_mandelbrot(t_comp *c, t_comp *z, t_comp *sqrz);
void		manage_mandelbrot(t_all *all);
void		manage_julia(t_all *all);
void   		violet(char *image_string, double count, double x, double y);
void   		red(char *image_string, double count, double x, double y);
void   		green(char *image_string, double count, double x, double y);
void		fill_pixel(char *image_string, int x, int y, t_color color);
int			mouse_func(int mousecode, int x, int y, t_all *all);
int			key_func(int keycode, t_all *all);
void		refresh_window(t_all *all);
void		zoom(t_all *all, int x, int y);
void		unzoom(t_all *all, int x, int y);
ptrcolor	*initcolor(void);
ptrfract 	*initfract();
void   		mandelbrot1(void *ptr);
void   		mandelbrot2(void *ptr);
void   		mandelbrot3(void *ptr);
void   		mandelbrot4(void *ptr);
void   		mandelbrot5(void *ptr);
void   		mandelbrot6(void *ptr);
void   		mandelbrot7(void *ptr);
void   		mandelbrot8(void *ptr);
void		conv(int x, int y, t_comp *conv, t_fract f);

#endif
