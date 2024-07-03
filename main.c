/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:08:40 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 19:25:41 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img0)
		mlx_destroy_image(vars->mlx, vars->img0);
	if (vars->img1)
		mlx_destroy_image(vars->mlx, vars->img1);
	if (vars->imgc)
		mlx_destroy_image(vars->mlx, vars->imgc);
	if (vars->imgp)
		mlx_destroy_image(vars->mlx, vars->imgp);
	if (vars->imge)
		mlx_destroy_image(vars->mlx, vars->imge);
	if (vars->imge2)
		mlx_destroy_image(vars->mlx, vars->imge2);
	if (vars->p1.img_d)
		mlx_destroy_image(vars->mlx, vars->p1.img_d);
	if (vars->p1.img_g)
		mlx_destroy_image(vars->mlx, vars->p1.img_g);
	if (vars->p2.img_d)
		mlx_destroy_image(vars->mlx, vars->p2.img_d);
	if (vars->p2.img_g)
		mlx_destroy_image(vars->mlx, vars->p2.img_g);
	if (vars->p3.img_d)
		mlx_destroy_image(vars->mlx, vars->p3.img_d);
	if (vars->p3.img_g)
		mlx_destroy_image(vars->mlx, vars->p3.img_g);
	if (vars->p1.d1)
		mlx_destroy_image(vars->mlx, vars->p1.d1);
	if (vars->p1.d2)
		mlx_destroy_image(vars->mlx, vars->p1.d2);
	if (vars->p1.d3)
		mlx_destroy_image(vars->mlx, vars->p1.d3);
	if (vars->p1.d4)
		mlx_destroy_image(vars->mlx, vars->p1.d4);
	if (vars->p1.d5)
		mlx_destroy_image(vars->mlx, vars->p1.d5);
	if (vars->p1.d6)
		mlx_destroy_image(vars->mlx, vars->p1.d6);
	if (vars->p1.d7)
		mlx_destroy_image(vars->mlx, vars->p1.d7);
	if (vars->p2.d1)
		mlx_destroy_image(vars->mlx, vars->p2.d1);
	if (vars->p2.d2)
		mlx_destroy_image(vars->mlx, vars->p2.d2);
	if (vars->p2.d3)
		mlx_destroy_image(vars->mlx, vars->p2.d3);
	if (vars->p2.d4)
		mlx_destroy_image(vars->mlx, vars->p2.d4);
	if (vars->p2.d5)
		mlx_destroy_image(vars->mlx, vars->p2.d5);
	if (vars->p2.d6)
		mlx_destroy_image(vars->mlx, vars->p2.d6);
	if (vars->p2.d7)
		mlx_destroy_image(vars->mlx, vars->p2.d7);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->key_state)
		free(vars->key_state);
	if (vars->map_pixel)
	{
		while (i < 976 && vars->map_pixel[i])
			free(vars->map_pixel[i++]);
		free(vars->map_pixel);
	}
	split_cleaner(vars);
	exit (0);
	return (0);
}

void	portal_open(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->e_pos.x * 65;
	y = vars->e_pos.y * 65;
	if (vars->goal == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imge2, y, x);
}

void	winning(t_vars *vars)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = vars->p1.x / 65;
	y1 = vars->p1.y / 65;
	x2 = vars->p2.x / 65;
	y2 = vars->p2.y / 65;
	if (!vars->goal)
	{
		if (vars->map_line[y1][x1] == 'E' && !vars->p1.dead)
		{
			ft_printf("********************\n* Congratulation ! *\n*    You win       *\n");
			ft_printf("********************\n");
			close_win(vars);
		}
		if (vars->map_line[y2][x2] == 'E' && !vars->p2.dead)
		{
			ft_printf("********************\n* Congratulation ! *\n*    You win       *\n");
			ft_printf("********************\n");
			close_win(vars);
		}
	}
}

void	collect_fish(t_vars *vars)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = vars->p1.x / 65;
	y1 = vars->p1.y / 65;
	x2 = vars->p2.x / 65;
	y2 = vars->p2.y / 65;
	if (vars->map_line[y1][x1] == 'C')
	{
		vars->goal--;
		vars->map_line[y1][x1] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, x1 * 65, y1 * 65);
	}
	if (vars->map_line[y2][x2] == 'C')
	{
		vars->goal--;
		vars->map_line[y2][x2] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, x2 * 65, y2 * 65);
	}
}

void	counter(t_vars *vars)
{
	char	*move;
	char	*left;

	left = ft_itoa(vars->goal);
	if (!left)
		close_win(vars);
	move = ft_itoa(vars->mv_count);
	if (!move)
	{
		free(left);
		close_win(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 65, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 195, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 260, 0);
	mlx_string_put(vars->mlx, vars->win, 15, 40, 0x00FFFFFF, move);
	mlx_string_put(vars->mlx, vars->win, 15, 20, 0x00FFFFFF, "Movement count :");
	mlx_string_put(vars->mlx, vars->win, 215, 40, 0x00FFFFFF, left);
	mlx_string_put(vars->mlx, vars->win, 215, 20, 0x00FFFFFF, "Collectible left :");
	free(move);
	free(left);
}

void	death_animation2(t_vars *vars)
{
	if (vars->p2.dead == 0)
		vars->death_j = 0;
	if (vars->death_j == 50)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.d1, vars->p2.x, vars->p2.y);
	if (vars->death_j == 100)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.d2, vars->p2.x, vars->p2.y);
	if (vars->death_j == 150)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.d3, vars->p2.x, vars->p2.y);
	if (vars->death_j == 200)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.d4, vars->p2.x, vars->p2.y);
	if (vars->death_j == 250)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.d5, vars->p2.x, vars->p2.y);
	if (vars->death_j == 300)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.d6, vars->p2.x, vars->p2.y);
	if (vars->death_j == 350)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.d7, vars->p2.x, vars->p2.y);
	if (vars->death_j >= 351)
		vars->death2 = 1;
}

void	death_animation1(t_vars *vars)
{
	if (vars->p1.dead == 0)
		vars->death_i = 0;
	if (vars->death_i == 50)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p1.d1, vars->p1.x, vars->p1.y);
	if (vars->death_i == 100)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p1.d2, vars->p1.x, vars->p1.y);
	if (vars->death_i == 150)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p1.d3, vars->p1.x, vars->p1.y);
	if (vars->death_i == 200)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p1.d4, vars->p1.x, vars->p1.y);
	if (vars->death_i == 250)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p1.d5, vars->p1.x, vars->p1.y);
	if (vars->death_i == 300)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p1.d6, vars->p1.x, vars->p1.y);
	if (vars->death_i == 350)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p1.d7, vars->p1.x, vars->p1.y);
	if (vars->death_i >= 351)
		vars->death1 = 1;
}

void	kill_player(t_vars *vars)
{
	if (vars->p1.x >= vars->p3.x - 65 && vars->p1.x <= vars->p3.x + 65 && vars->p1.y >= vars->p3.y - 65 && vars->p3.y && vars->p1.y <= vars->p3.y + 65)
		if (vars->i <= 0 && !vars->p1.dead && vars->goal)
			vars->p1.dead = 1;
	if (vars->p2.x >= vars->p3.x - 65 && vars->p2.x <= vars->p3.x + 65 && vars->p2.y >= vars->p3.y - 65 && vars->p3.y && vars->p2.y <= vars->p3.y + 65)
		if (vars->i <= 0 && !vars->p2.dead && vars->goal)
			vars->p2.dead = 1;
	if (vars->p1.dead && vars->p2.dead && vars->death1 == 1 && vars->death2 == 1)
	{
		ft_printf("**************\n");
		ft_printf("* Game Over! *\n* You lose ! *\n");
		ft_printf("**************\n");
		close_win(vars);
	}
}


int	update(t_vars *vars)
{
	vars->update_counter++;
	if (vars->update_counter >= 400)
	{
		counter(vars);
		press_button(vars);
		if (vars->key_state[ARROW_UP] && vars->map_pixel[vars->p2.y - 1][vars->p2.x] != 1)
		{
			if (!vars->p2.dead)
			{
				vars->mv_count += 1;
				vars->p2.y -= 1;
				if (vars->key_state[ARROW_RIGHT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_d, vars->p2.x, vars->p2.y);
				else if (vars->key_state[ARROW_LEFT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_g, vars->p2.x, vars->p2.y);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_g, vars->p2.x, vars->p2.y);
			}
		}
		if (vars->key_state[ARROW_DOWN] && vars->map_pixel[vars->p2.y + 1][vars->p2.x] != 1)
		{
			if (!vars->p2.dead)
			{
				vars->mv_count += 1;
				vars->p2.y += 1;
				if (vars->key_state[ARROW_RIGHT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_d, vars->p2.x, vars->p2.y);
				else if (vars->key_state[ARROW_LEFT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_g, vars->p2.x, vars->p2.y);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_g, vars->p2.x, vars->p2.y);
			}
		}
		if (vars->key_state[ARROW_LEFT] && vars->map_pixel[vars->p2.y][vars->p2.x - 1] != 1)
		{
			if (!vars->p2.dead)
			{
				vars->mv_count += 1;
				vars->p2.x -= 1;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_g, vars->p2.x, vars->p2.y);
			}
		}
		if (vars->key_state[ARROW_RIGHT] && vars->map_pixel[vars->p2.y][vars->p2.x + 1] != 1)
		{
			if (!vars->p2.dead)
			{
				vars->mv_count += 1;
				vars->p2.x += 1;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->p2.img_d, vars->p2.x, vars->p2.y);
			}
		}
		if (vars->mouse_pressed == 1)
		{
			if (vars->i <= 0)
			{
				if (vars->p3.x > vars->mouse_x - 32 && vars->p3.x > 65)
				{
					vars->p3.x -= 1;
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_g, vars->p3.x, vars->p3.y);
				}
				if (vars->p3.x < vars->mouse_x - 32 && vars->p3.x < 1755)
				{	
					vars->p3.x += 1;
					mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_d, vars->p3.x, vars->p3.y);
				}
				if (vars->p3.y > vars->mouse_y - 32 && vars->p3.y > 65)
				{	
					vars->p3.y -= 1;
					if (vars->p3.x > vars->mouse_x - 32)
						mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_g, vars->p3.x, vars->p3.y);
					else
						mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_d, vars->p3.x, vars->p3.y);
				}
				if (vars->p3.y < vars->mouse_y - 32 && vars->p3.y < 845)
				{
					vars->p3.y += 1;
					if (vars->p3.x > vars->mouse_x - 32)
						mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_g, vars->p3.x, vars->p3.y);
					else
						mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_d, vars->p3.x, vars->p3.y);
				}
				vars->i = 3;
			}
		}
		vars->i--;
		if (vars->boost_i >= 4242)
		{
			if (vars->boost_i == 4242)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgp, vars->p_pos.y * 65, vars->p_pos.x * 65);
			if (vars->p1.x == vars->p_pos.y * 65 && vars->p1.y == vars->p_pos.x * 65)
			{
				if (!vars->p1.dead)
				{
					vars->boost_i = 0;
					init_map(vars);
				}
			}
			if (vars->p2.x == vars->p_pos.y * 65 && vars->p2.y == vars->p_pos.x * 65)
			{
				if (!vars->p2.dead)
				{
					vars->boost_i = 0;
					init_map(vars);
				}
			}
		}
		kill_player(vars);
		if (vars->death1 == 0)
			death_animation1(vars);
		if (vars->death2 == 0)
			death_animation2(vars);
		collect_fish(vars);
		winning(vars);
		portal_open(vars);
		vars->death_i++;
		vars->death_j++;
		vars->boost_i++;
		vars->update_counter = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars_declare1(&vars, argc, argv);
	vars_declare2(&vars);
	vars_declare3(&vars, vars.map_width, vars.map_height);
	vars_declare4(&vars, &vars.img);
	vars_declare5(&vars, &vars.img);
	vars_declare6(&vars, &vars.img);
	vars_declare7(&vars, &vars.img);
	init_map(&vars);
	init_zone(&vars);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_loop(vars.mlx);
}
