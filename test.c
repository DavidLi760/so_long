/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:04 by davli             #+#    #+#             */
/*   Updated: 2024/06/27 15:51:03 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_forbidden_zone(t_vars *vars, int i, int j)
{
    int forbidden;
    int temp_i;
    int temp_j;

    if (vars->map_line[i][j] == '1')
        forbidden = 1;
    else
        forbidden = 0;
    temp_i = i * 65;
    while (temp_i <= (i * 65 + 65))
    {
        temp_j = j * 65;
        while (temp_j <= (j * 65 + 65))
        {
            if (forbidden == 1)
                vars->map_pixel[temp_i][temp_j] = 1;
            else if (forbidden == 0)
                vars->map_pixel[temp_i][temp_j] = 0;
            temp_j++;
        }
        temp_i++;
    }
}

void    forbidden_zone(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (vars->map_line[i])
    {
        j = 0;
        while (vars->map_line[i][j])
        {
            init_forbidden_zone(vars, i, j);
            j++;
        }
        i++;
    }
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int	i;
	int	j;

	check_arg(&vars, argc, argv);
	init_map(&vars);
	forbidden_zone(&vars);
	i = 0;
	while (vars.map_pixel[i])
	{
		j = 0;
		while (vars.map_pixel[i][j])
		{
			printf("%d, ", vars.map_pixel[i][j]);
			j++;
		}
		i++;
	}
}
