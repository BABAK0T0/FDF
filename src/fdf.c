/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 19:16:49 by nrandria          #+#    #+#             */
/*   Updated: 2016/04/26 14:17:58 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_tab_line(char **tmp, char *line)
{
	free(tmp);
	free(line);
}

int			key_hook(int key, t_info *info)
{
	(key == 53) ? exit(2) : 0;
	info->zoom += (key == 69) ? 1 : 0;
	info->zoom -= (key == 78 && info->zoom > 1) ? 1 : 0;
	info->xstart += (key == 124) ? info->zoom * 10 : 0;
	info->xstart -= (key == 123) ? info->zoom * 10 : 0;
	info->ystart += (key == 125) ? info->zoom * 10 : 0;
	info->ystart -= (key == 126) ? info->zoom * 10 : 0;
	info->deep -= (key == 116 && info->deep > 1) ? 1 : 0;
	info->deep += (key == 121) ? 1 : 0;
	if (key == 8)
	{
		info->color_r += 5;
		info->color_g += 5 * 5;
		info->color_b += 5 * 5 * 5;
	}
	put_img(info);
	return (1);
}

t_point		*get_lst_nb(t_list *list, t_info *info)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	i = 0;
	while (i < info->line_size)
	{
		i++;
		tmp = tmp->next;
	}
	return ((t_point *)tmp->content);
}

void		init_info(t_info *info)
{
	info->xstart = 900;
	info->ystart = 600;
	info->zoom = 10;
	info->deep = 5;
	info->color_r = 255;
	info->color_g = 255;
	info->color_b = 255;
}

int			main(int ac, char **av)
{
	t_info	info;

	if (ac > 2 || ac == 1)
	{
		ft_putstr_fd("Usage : ./fdf <filename>\n", 2);
		exit(2);
	}
	else
	{
		info.mlx = mlx_init();
		info.win = mlx_new_window(info.mlx, WIDTH, HEIGTH, "FDF_42");
		get_coord(av[1], &info);
		init_info(&info);
		put_img(&info);
		mlx_hook(info.win, 2, 3, key_hook, &info);
		mlx_loop(info.mlx);
	}
}
