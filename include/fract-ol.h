/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fract-ol.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:08:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 05:50:34 by befuhro     ###    #+. /#+    ###.fr     */
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

typedef	void	(*ptr2func)(char *, float, float, float);

typedef struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_color;

typedef struct	s_all
{
	void			*init;
	void			*win;
	void			*image_ptr;
	char			*image_string;
	ptr2func  		*ptrColor;
	int				indexColor;
}				t_all;

void	mandelbrot(char *image_string, ptr2func ptr);
int		ft_hex1(float *z);
int		ft_hex2(float *z);
void    first_color(char *image_string, float count, float x, float y);
void    second_color(char *image_string, float count, float x, float y);
void    third_color(char *image_string, float count, float x, float y);
void	fill_pixel(char *image_string, int x, int y, t_color color);
int		mouse_func(int mousecode, t_all *all);
ptr2func	*makeTab(void);

#endif
