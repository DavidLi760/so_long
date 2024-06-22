/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:33:57 by davli             #+#    #+#             */
/*   Updated: 2024/06/22 19:07:40 by davli            ###   ########.fr       */
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
	char	*line;
	int	line_len;
	int	current_len;

	line_len = -1;
	line = get_next_line(vars->map_fd);
	while (line != NULL)
	{
		current_len = strlen(line);
		if (line_len == -1)
			line_len = current_len;
		else if (current_len != line_len)
		{
			free(line);
			return 0;
		}
	}
	free(line);
	return 1;
}

int	check_map(char **argv, t_vars *vars)
{
	if (check_opening(argv[1], vars) == 0)
		return (-9);
	if (check_rectangular(vars))
		return (-1);
	return (0);
}

void	map_error(int argc, char **argv, t_vars *vars)
{
	int	error;

	if (argc < 2)
		exit (1);
	error = check_map(argv, vars);
	if (argc != 2)
		error = -9;
	if (error == -1)
		ft_printf("Error %d: Problem with the map\n", error);
	if (error == -9)
		ft_printf("Error %d: Use ./so_long [map_name].ber\n", error);
}

int	check_wall(char	*line)
{
	int	i;

	i = 0;
	while ()
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	i = 0;
	vars.map_fd = open(argv[1], O_RDONLY);
	if (vars.map_fd < 0)
		return (0);
	while (vars.map_buf)
	{
		vars.map_buf = get_next_line(fd);
		vars.map_line[i++] = vars.map_buf;
	}
	if (i < )
	while (vars.map_line)
	{
		check_wall(vars.map_line)
		vars.map_line = get_next_line(fd);
	}
	map_error(argc, argv, &vars);
}
