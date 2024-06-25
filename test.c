/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:04 by davli             #+#    #+#             */
/*   Updated: 2024/06/25 15:17:17 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    fill(char **tab, int x, int y, char to_fill)
{
    if (tab[x][y] == '1')
        return ;
    tab[x][y] = 'V';
    fill(tab, (x - 1), y, to_fill);
    fill(tab, (x + 1), y, to_fill);
    fill(tab, x, (y - 1), to_fill);
    fill(tab, x, (y + 1), to_fill);
}

int flood_fill(t_vars *vars)
{
    fill(vars->map_temp, vars->p_pos.x, vars->p_pos.y, 'V');
    if (vars->map_temp[vars->e_pos.x][vars->e_pos.y] == 'V' && !vars->c_count)
        return (1);
    exit (0);
}

int main(int argc, char **argv)
{
    t_vars  vars;
    int     i;

	(void)argc;
    i = 0;
    vars.map_fd = open(argv[1], O_RDONLY);
    if (vars.map_fd < 0)
        return (0);
    vars.map_buf = get_next_line(vars.map_fd);
    vars.map_line = ft_split(vars.map_buf, '\n');
    vars.map_temp = ft_split(vars.map_buf, '\n');
    flood_fill(&vars);
    printf("Success\n");
    return (0);
}

