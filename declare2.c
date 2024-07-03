/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:25:19 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 19:25:20 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_declare6(t_vars *vars, int *m)
{
	vars->p1.d5 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort5.xpm", m, m);
	if (!vars->p1.d5)
		close_win(vars);
	vars->p1.d6 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort6.xpm", m, m);
	if (!vars->p1.d6)
		close_win(vars);
	vars->p1.d7 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort7.xpm", m, m);
	if (!vars->p1.d7)
		close_win(vars);
	vars->p2.d1 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort1.xpm", m, m);
	if (!vars->p2.d1)
		close_win(vars);
	vars->p2.d2 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort2.xpm", m, m);
	if (!vars->p2.d2)
		close_win(vars);
	vars->p2.d3 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort3.xpm", m, m);
	if (!vars->p2.d3)
		close_win(vars);
	vars->p2.d4 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort4.xpm", m, m);
	if (!vars->p2.d4)
		close_win(vars);
	vars->p2.d5 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort5.xpm", m, m);
	if (!vars->p2.d5)
		close_win(vars);
}

void	vars_declare7(t_vars *vars, int *m)
{
	vars->p2.d6 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort6.xpm", m, m);
	if (!vars->p2.d6)
		close_win(vars);
	vars->p2.d7 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort7.xpm", m, m);
	if (!vars->p2.d7)
		close_win(vars);
}
