/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:26:07 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 19:41:34 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(t_vars *vars, int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		exit(-1);
	vars->map_fd = open(argv[1], O_RDONLY);
	if (vars->map_fd < 0)
		exit (-1);
	vars->map_buf = get_next_line(vars->map_fd);
	if (!vars->map_buf)
		exit ((free(vars->map_buf), 1));
	vars->map_line = ft_split(vars->map_buf, '\n');
	if (!vars->map_line)
		exit ((free(vars->map_buf), 1));
	vars->map_temp = ft_split(vars->map_buf, '\n');
	if (!vars->map_temp)
	{
		vars->map_temp = NULL;
		vars->map_line = NULL;
		split_cleaner(vars);
	}
	map_error(vars);
}

void	init_map_util(t_vars *vars, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i * 65;
	j2 = j * 65;
	if (vars->map_line[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, j2, i2);
	if (vars->map_line[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, j2, i2);
	if (vars->map_line[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgc, j2, i2);
	if (vars->map_line[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgp, j2, i2);
	if (vars->map_line[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imge, j2, i2);
}

void	init_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
		{
			init_map_util(vars, i, j);
			j++;
		}
		i++;
	}
}

void	forbidden_zone(t_vars *vars, int i, int j)
{
	int	forbidden;
	int	temp_i;
	int	temp_j;

	forbidden = 0;
	if (vars->map_line[i][j] == '1')
		forbidden = 1;
	temp_i = i * 65;
	temp_j = j * 65;
	while (temp_i <= (i + 1) * 65)
	{
		temp_j = j * 65;
		while (temp_j <= (j + 1) * 65)
		{
			if (forbidden == 1 && i > 0 && j > 0)
			{
				vars->map_pixel[temp_i - 64][temp_j - 1] = forbidden;
				vars->map_pixel[temp_i - 1][temp_j - 64] = forbidden;
				vars->map_pixel[temp_i - 64][temp_j - 64] = forbidden;
			}
			vars->map_pixel[temp_i][temp_j] = forbidden;
			temp_j++;
		}
		temp_i++;
	}
}

void	init_zone(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
		{
			forbidden_zone(vars, i, j);
			j++;
		}
		i++;
	}
	vars->p1.x = vars->p_pos.y * 65;
	vars->p1.y = vars->p_pos.x * 65;
	vars->p2.x = vars->p_pos.y * 65;
	vars->p2.y = vars->p_pos.x * 65;
	vars->p3.x = vars->e_pos.y * 65;
	vars->p3.y = vars->e_pos.x * 65;
	vars->update_counter = 101;
}
