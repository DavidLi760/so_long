/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:33:57 by davli             #+#    #+#             */
/*   Updated: 2024/06/24 18:52:31 by davli            ###   ########.fr       */
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
