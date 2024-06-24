/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:33:57 by davli             #+#    #+#             */
/*   Updated: 2024/06/24 19:49:58 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_opening(char *argv, t_vars *vars)
{
	int	len;

	len = 0;
	len = ft_strlen(argv);
	if (len < 4)
		return (0);
	if (ft_strcmp(&argv[len - 4], ".ber") != 0)
		return (0);
	vars->map_fd = open(argv, O_RDONLY);
	if (vars->map_fd < 0)
		return (0);
	return (1);
}

int	check_rectangular(t_vars *vars)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (vars->map_line[i][width])
		width++;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
			j++;
		if (width != j)
			return (0);
		i++;
	}
	if (i > 15)
		return (0);
	return (1);
}

int	is_closed(t_vars *vars)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	j = 0;
	height = 0;
	width = 0;
	while (vars->map_line[height])
		height++;
	while (vars->map_line[i][width])
		width++;
	while (vars->map_line[i])
	{
		j = 0;
		if (vars->map_line[0][j] != '1' || vars->map_line[height - 1][j] != '1')
			return (0);
		while (vars->map_line[i][j])
		{
			if (vars->map_line[i][0] != '1' || vars->map_line[i][width - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	char_counter(char c, t_vars *vars)
{
	if (c == 'E')
		vars->e_count++;
	if (c == 'C')
		vars->c_count++;
	if (c == 'P')
		vars->p_count++;	
}

int	check_correct_char(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
		{
			char_counter(vars->map_line[i][j], vars);
			j++;
		}
		i++;
	}
	if (vars->e_count != 1 || vars->p_count != 1 || vars->c_count < 1)
		return (0);
	return (1);
}

void	fill(char **tab, int x, int y, char to_fill)
{
	tab[x][y] = 'V';
	fill(tab, x - 1, y, to_fill);
	fill(tab, x + 1, y, to_fill);
	fill(tab, x, y - 1, to_fill);
	fill(tab, x, y + 1, to_fill);
}

int	flood_fill(char **tab, t_vars *vars)
{
	fill(tab, x, y, letter);
	if (tab[x][y] == 'V' && vars->c_count)
		return (1);
	return (0);
}

int	

int	exit_error(int error, t_vars *vars)
{
	int	i;

	i = 0;
	if (error == -9)
    	ft_printf("Error : Map incorrect size");
	if (error == -8)
		ft_printf("Error : Map wall not closed");
	if (error == -7)
		ft_printf("Error : Doesn't have 1 exit, 1 player spawn, at least 1 collectible");
	
	while (vars->map_line[i])
		free(vars->map_line[i++]);
	free(vars->)
    exit (1);
}



void	map_error(int argc, t_vars *vars)
{
	if (argc < 2 || argc > 2)
		exit_error(-9, vars);
	if (!check_rectangular(vars))
		exit_error(-9, vars);
	if (!is_closed(vars))
		exit_error(-8, vars);
	if (!check_correct_char(vars))
		exit_error(-7, vars);
	vars->map_x = 0;
	while (vars->map_line[vars->map_x])
	{
		vars->max_y = 0;
		while (vars->map_line[vars->map_x][vars->map_y])
		{
			if (vars->map_line[vars->map_x][vars->map_y] == 'P')
			{
				vars->p_pos.x = vars->map_x;
				vars->p_pos.y = vars->map_y;
			}
			if (vars->map_line[vars->map_x][vars->map_y] == 'E')
			{
				vars->e_pos.x = vars->map_x;
				vars->e_pos.y = vars->map_y;
			}
			vars->map_y++;
		}
		vars->map_x++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	i = 0;
	vars.map_fd = open(argv[1], O_RDONLY);
	if (vars.map_fd < 0)
		return (0);
	vars.map_buf = get_next_line(vars.map_fd);
	vars.map_line = ft_split(vars.map_buf, '\n');
	map_error(argc, &vars);
	printf("Success\n");
	while (vars.map_line[i])
		free(vars.map_line[i++]);
	free(vars.map_line);
	free(vars.map_buf);
	close(vars.map_fd);
	return (0);
}
