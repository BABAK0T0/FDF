/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:52:13 by nrandria          #+#    #+#             */
/*   Updated: 2016/10/27 16:18:22 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# define HEIGTH 2000
# define WIDTH 1800
# define ERROR ft_putstr_fd("Found wrong line length. Exiting.\n", 2); exit(-1);

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					nb;
}						t_point;

typedef struct			s_algo
{
	int					dx;
	int					sx;
	int					dy;
	int					sy;
	int					err;
	int					e2;
}						t_algo;

typedef struct			s_info
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*ptr_img;
	int					nb_line;
	int					line_size;
	int					bpp;
	int					img_line;
	int					endian;
	int					xstart;
	int					ystart;
	int					zoom;
	int					deep;
	int					color_r;
	int					color_g;
	int					color_b;
	t_list				*list;
}						t_info;

void					free_tab_line(char **tmp, char *line);
void					check_file(char *file);
void					ft_error(char *file);
void					check_length(int x, int y, t_info *i);
void					init_info(t_info *info);
t_point					*get_lst_nb(t_list *list, t_info *info);
void					add_pixel(int x, int y, int z, t_info *i);
void					get_coord(char *file, t_info *info);
void					put_img(t_info *i);
void					put_map(t_info *i);
void					put_line(t_point p1, t_point p2, t_info *i);
void					put_pixel(int x, int y, t_info *i);
t_point					calcul(t_point *p, t_info *i);

#endif
