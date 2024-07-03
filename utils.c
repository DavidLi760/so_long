/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:51:29 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 18:24:35 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	split_cleaner(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map_line)
		while (vars->map_line[i])
			free(vars->map_line[i++]);
	i = 0;
	if (vars->map_temp)
		while (vars->map_temp[i])
			free(vars->map_temp[i++]);
	free(vars->map_line);
	free(vars->map_temp);
	free(vars->map_buf);
	close(vars->map_fd);
	exit (0);
}

void	exit_error(int error, t_vars *vars)
{
	if (error == -9)
		ft_printf("Error : Map incorrect size");
	if (error == -8)
		ft_printf("Error : Map wall not closed");
	if (error == -7)
		ft_printf("Error : Need 1 exit, 1 player spawn and 1+ collectible");
	if (error == -6)
		ft_printf("Error : Map doesn't have valid path");
	if (error == -5)
		ft_printf("Error : Map has unknown characters");
	split_cleaner(vars);
	exit (1);
}
