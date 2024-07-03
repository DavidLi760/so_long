/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:08:40 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 17:23:05 by davli            ###   ########.fr       */
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
	if (vars->player1.img_d)
		mlx_destroy_image(vars->mlx, vars->player1.img_d);
	if (vars->player1.img_g)
		mlx_destroy_image(vars->mlx, vars->player1.img_g);
	if (vars->player2.img_d)
		mlx_destroy_image(vars->mlx, vars->player2.img_d);
	if (vars->player2.img_g)
		mlx_destroy_image(vars->mlx, vars->player2.img_g);
	if (vars->player3.img_d)
		mlx_destroy_image(vars->mlx, vars->player3.img_d);
	if (vars->player3.img_g)
		mlx_destroy_image(vars->mlx, vars->player3.img_g);
	if (vars->player1.d1)
		mlx_destroy_image(vars->mlx, vars->player1.d1);
	if (vars->player1.d2)
		mlx_destroy_image(vars->mlx, vars->player1.d2);
	if (vars->player1.d3)
		mlx_destroy_image(vars->mlx, vars->player1.d3);
	if (vars->player1.d4)
		mlx_destroy_image(vars->mlx, vars->player1.d4);
	if (vars->player1.d5)
		mlx_destroy_image(vars->mlx, vars->player1.d5);
	if (vars->player1.d6)
		mlx_destroy_image(vars->mlx, vars->player1.d6);
	if (vars->player1.d7)
		mlx_destroy_image(vars->mlx, vars->player1.d7);
	if (vars->player2.d1)
		mlx_destroy_image(vars->mlx, vars->player2.d1);
	if (vars->player2.d2)
		mlx_destroy_image(vars->mlx, vars->player2.d2);
	if (vars->player2.d3)
		mlx_destroy_image(vars->mlx, vars->player2.d3);
	if (vars->player2.d4)
		mlx_destroy_image(vars->mlx, vars->player2.d4);
	if (vars->player2.d5)
		mlx_destroy_image(vars->mlx, vars->player2.d5);
	if (vars->player2.d6)
		mlx_destroy_image(vars->mlx, vars->player2.d6);
	if (vars->player2.d7)
		mlx_destroy_image(vars->mlx, vars->player2.d7);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->key_state)
		free(vars->key_state);
	while (i < 976)
		free(vars->map_pixel[i++]);
	free(vars->map_pixel);
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
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imge2, y, x);
	}
}

void	winning(t_vars *vars)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = vars->player1.x / 65;
	y1 = vars->player1.y / 65;
	x2 = vars->player2.x / 65;
	y2 = vars->player2.y / 65;
	if (!vars->goal)
	{
		if (vars->map_line[y1][x1] == 'E' && !vars->player1.dead)
		{
			ft_printf("********************\n* Congratulation ! *\n*    You win       *\n");
			ft_printf("********************\n");
			close_win(vars);
		}
		if (vars->map_line[y2][x2] == 'E' && !vars->player2.dead)
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

	x1 = vars->player1.x / 65;
	y1 = vars->player1.y / 65;
	x2 = vars->player2.x / 65;
	y2 = vars->player2.y / 65;
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
	move = ft_itoa(vars->mv_count);
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

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	else if (keycode >= 0 && keycode < 65365)
		vars->key_state[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode >= 0 && keycode < 65365)
		vars->key_state[keycode] = 0;
	return (0);
}

void	death_animation2(t_vars *vars)
{
	if (vars->player2.dead == 0)
		vars->death_j = 0;
	if (vars->death_j == 50)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.d1, vars->player2.x, vars->player2.y);
	if (vars->death_j == 100)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.d2, vars->player2.x, vars->player2.y);
	if (vars->death_j == 150)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.d3, vars->player2.x, vars->player2.y);
	if (vars->death_j == 200)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.d4, vars->player2.x, vars->player2.y);
	if (vars->death_j == 250)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.d5, vars->player2.x, vars->player2.y);
	if (vars->death_j == 300)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.d6, vars->player2.x, vars->player2.y);
	if (vars->death_j == 350)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.d7, vars->player2.x, vars->player2.y);
	if (vars->death_j >= 351)
		vars->death2 = 1;
}

void	death_animation1(t_vars *vars)
{
	if (vars->player1.dead == 0)
		vars->death_i = 0;
	if (vars->death_i == 50)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.d1, vars->player1.x, vars->player1.y);
	if (vars->death_i == 100)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.d2, vars->player1.x, vars->player1.y);
	if (vars->death_i == 150)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.d3, vars->player1.x, vars->player1.y);
	if (vars->death_i == 200)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.d4, vars->player1.x, vars->player1.y);
	if (vars->death_i == 250)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.d5, vars->player1.x, vars->player1.y);
	if (vars->death_i == 300)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.d6, vars->player1.x, vars->player1.y);
	if (vars->death_i == 350)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.d7, vars->player1.x, vars->player1.y);
	if (vars->death_i >= 351)
		vars->death1 = 1;
}

void	kill_player(t_vars *vars)
{
	if (vars->player1.x >= vars->player3.x - 65 && vars->player1.x <= vars->player3.x + 65 && vars->player1.y >= vars->player3.y - 65 && vars->player3.y && vars->player1.y <= vars->player3.y + 65)
		if (vars->i <= 0 && !vars->player1.dead && vars->goal)
			vars->player1.dead = 1;
	if (vars->player2.x >= vars->player3.x - 65 && vars->player2.x <= vars->player3.x + 65 && vars->player2.y >= vars->player3.y - 65 && vars->player3.y && vars->player2.y <= vars->player3.y + 65)
		if (vars->i <= 0 && !vars->player2.dead && vars->goal)
			vars->player2.dead = 1;
	if (vars->player1.dead && vars->player2.dead && vars->death1 == 1 && vars->death2 == 1)
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
		if (vars->key_state[W] && vars->map_pixel[vars->player1.y - 1][vars->player1.x] != 1)
		{
			if (!vars->player1.dead)
			{
				vars->mv_count += 1;
				vars->player1.y -= 1;
				if (vars->key_state[D])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
				else if (vars->key_state[A])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
			}
		}
		if (vars->key_state[S] && vars->map_pixel[vars->player1.y + 1][vars->player1.x] != 1)
		{
			if (!vars->player1.dead)
			{
				vars->mv_count += 1;
				vars->player1.y += 1;
				if (vars->key_state[D])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
				else if (vars->key_state[A])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
			}
		}
		if (vars->key_state[A] && vars->map_pixel[vars->player1.y][vars->player1.x - 1] != 1)
		{
			if (!vars->player1.dead)
			{
				vars->mv_count += 1;
				vars->player1.x -= 1;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
			}
		}
		if (vars->key_state[D] && vars->map_pixel[vars->player1.y][vars->player1.x + 1] != 1)
		{
			if (!vars->player1.dead)
			{
				vars->mv_count += 1;
				vars->player1.x += 1;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
			}
		}
		if (vars->key_state[ARROW_UP] && vars->map_pixel[vars->player2.y - 1][vars->player2.x] != 1)
		{
			if (!vars->player2.dead)
			{
				vars->mv_count += 1;
				vars->player2.y -= 1;
				if (vars->key_state[ARROW_RIGHT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_d, vars->player2.x, vars->player2.y);
				else if (vars->key_state[ARROW_LEFT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
			}
		}
		if (vars->key_state[ARROW_DOWN] && vars->map_pixel[vars->player2.y + 1][vars->player2.x] != 1)
		{
			if (!vars->player2.dead)
			{
				vars->mv_count += 1;
				vars->player2.y += 1;
				if (vars->key_state[ARROW_RIGHT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_d, vars->player2.x, vars->player2.y);
				else if (vars->key_state[ARROW_LEFT])
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
			}
		}
		if (vars->key_state[ARROW_LEFT] && vars->map_pixel[vars->player2.y][vars->player2.x - 1] != 1)
		{
			if (!vars->player2.dead)
			{
				vars->mv_count += 1;
				vars->player2.x -= 1;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
			}
		}
		if (vars->key_state[ARROW_RIGHT] && vars->map_pixel[vars->player2.y][vars->player2.x + 1] != 1)
		{
			if (!vars->player2.dead)
			{
				vars->mv_count += 1;
				vars->player2.x += 1;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_d, vars->player2.x, vars->player2.y);
			}
		}
		if (vars->mouse_pressed == 1)
		{
			if (vars->i <= 0)
			{
				if (vars->player3.x > vars->mouse_x - 32 && vars->player3.x > 65)
				{
					vars->player3.x -= 1;
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player3.img_g, vars->player3.x, vars->player3.y);
				}
				if (vars->player3.x < vars->mouse_x - 32 && vars->player3.x < 1755)
				{	
					vars->player3.x += 1;
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player3.img_d, vars->player3.x, vars->player3.y);
				}
				if (vars->player3.y > vars->mouse_y - 32 && vars->player3.y > 65)
				{	
					vars->player3.y -= 1;
					if (vars->player3.x > vars->mouse_x - 32)
						mlx_put_image_to_window(vars->mlx, vars->win, vars->player3.img_g, vars->player3.x, vars->player3.y);
					else
						mlx_put_image_to_window(vars->mlx, vars->win, vars->player3.img_d, vars->player3.x, vars->player3.y);
				}
				if (vars->player3.y < vars->mouse_y - 32 && vars->player3.y < 845)
				{
					vars->player3.y += 1;
					if (vars->player3.x > vars->mouse_x - 32)
						mlx_put_image_to_window(vars->mlx, vars->win, vars->player3.img_g, vars->player3.x, vars->player3.y);
					else
						mlx_put_image_to_window(vars->mlx, vars->win, vars->player3.img_d, vars->player3.x, vars->player3.y);
				}
				vars->i = 3;
			}
		}
		vars->i--;
		if (vars->boost_i >= 4242)
		{
			if (vars->boost_i == 4242)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgp, vars->p_pos.y * 65, vars->p_pos.x * 65);
			if (vars->player1.x == vars->p_pos.y * 65 && vars->player1.y == vars->p_pos.x * 65)
			{
				if (!vars->player1.dead)
				{
					vars->boost_i = 0;
					init_map(vars);
				}
			}
			if (vars->player2.x == vars->p_pos.y * 65 && vars->player2.y == vars->p_pos.x * 65)
			{
				if (!vars->player2.dead)
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

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->mouse_pressed = 1;
	vars->mouse_x = x;
	vars->mouse_y = y;
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->mouse_pressed = 0;
	vars->mouse_x = x;
	vars->mouse_y = y;
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->mouse_pressed == 1)
	{
		vars->mouse_x = x;
		vars->mouse_y = y;
	}
	return (0);
}

void	check_arg(t_vars *vars, int	argc, char **argv)
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
			if (vars->map_line[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, j * 65, i * 65);
			if (vars->map_line[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, j * 65, i * 65);
			if (vars->map_line[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgc, j * 65, i * 65);
			if (vars->map_line[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgp, j * 65, i * 65);
			if (vars->map_line[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imge, j * 65, i * 65);
			j++;
		}
		i++;
	}
}

void	forbidden_zone(t_vars *vars, int i, int j)
{
	int	forbidden;
	int		temp_i;
	int		temp_j;

	if (vars->map_line[i][j] == '1')
		forbidden = 1;
	else
		forbidden = 0;
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
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	vars.i = 2500;
	vars.player1.dead = 0;
	vars.player2.dead = 0;
	vars.death_i = 0;
	vars.death_j = 0;
	vars.death1 = 0;
	vars.death2 = 0;
	vars.boost_i = 0;
	vars.c_count = 0;
	vars.e_count = 0;
	vars.p_count = 0;
	check_arg(&vars, argc, argv);
	vars.mv_count = 0;
	vars.mouse_pressed = 0;
	vars.goal = vars.c_left;
	vars.mlx = NULL;
	vars.win = NULL;
	vars.key_state = NULL;
	vars.map_pixel = NULL;
	vars.img0 = NULL;
	vars.img1 = NULL;
	vars.imgp = NULL;
	vars.imge = NULL;
	vars.imge2 = NULL;
	vars.imgc = NULL;
	vars.player1.img_d = NULL;
	vars.player1.img_g = NULL;
	vars.player2.img_d = NULL;
	vars.player2.img_g = NULL;
	vars.player3.img_d = NULL;
	vars.player3.img_g = NULL;
	vars.player1.d1 = NULL;
	vars.player1.d2 = NULL;
	vars.player1.d3 = NULL;
	vars.player1.d4 = NULL;
	vars.player1.d5 = NULL;
	vars.player1.d6 = NULL;
	vars.player1.d7 = NULL;
	vars.player2.d1 = NULL;
	vars.player2.d2 = NULL;
	vars.player2.d3 = NULL;
	vars.player2.d4 = NULL;
	vars.player2.d5 = NULL;
	vars.player2.d6 = NULL;
	vars.player2.d7 = NULL;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (-1);
	vars.win = mlx_new_window(vars.mlx, vars.map_width * 65, vars.map_height * 65, "so_long");
	if (!vars.mlx)
	{
		free(vars.mlx);
		return (1);
	}
	i = 0;
	vars.key_state = malloc(sizeof(int) * 65365);
	if (!vars.key_state)
		close_win(&vars);
	vars.map_pixel = malloc(sizeof(int *) * 976);
	while (i < 976)
		vars.map_pixel[i++] = malloc(sizeof(int) * 1886);
	i = 0;
	while (i < 65365)
		vars.key_state[i++] = 0;
	vars.img0 = mlx_xpm_file_to_image(vars.mlx, "xpm/Eau.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img0)
		close_win(&vars);
	vars.imgp = mlx_xpm_file_to_image(vars.mlx, "xpm/Spawn.xpm", &vars.img_width, &vars.img_height);
	if (!vars.imgp)
		close_win(&vars);
	vars.img1 = mlx_xpm_file_to_image(vars.mlx, "xpm/Wall.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img1)
		close_win(&vars);
	vars.imgc = mlx_xpm_file_to_image(vars.mlx, "xpm/Collectible.xpm", &vars.img_width, &vars.img_height);
	if (!vars.imgc)
		close_win(&vars);
	vars.imge = mlx_xpm_file_to_image(vars.mlx, "xpm/PortalClose.xpm", &vars.img_width, &vars.img_height);
	if (!vars.imge)
		close_win(&vars);
	vars.imge2 = mlx_xpm_file_to_image(vars.mlx, "xpm/PortalOpen.xpm", &vars.img_width, &vars.img_height);
	if (!vars.imge2)
		close_win(&vars);
	vars.player1.img_d = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1d.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.img_d)
		close_win(&vars);
	vars.player1.img_g = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1g.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.img_g)
		close_win(&vars);
	vars.player2.img_g = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2g.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.img_g)
		close_win(&vars);
	vars.player2.img_d = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2d.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.img_d)
		close_win(&vars);
	vars.player3.img_g = mlx_xpm_file_to_image(vars.mlx, "xpm/Shinigami2g.xpm", &vars.player3.x, &vars.player3.y);
	if (!vars.player3.img_g)
		close_win(&vars);
	vars.player3.img_d = mlx_xpm_file_to_image(vars.mlx, "xpm/Shinigami2d.xpm", &vars.player3.x, &vars.player3.y);
	if (!vars.player3.img_d)
		close_win(&vars);
	vars.player1.d1 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1mort1.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.d1)
		close_win(&vars);
	vars.player1.d2 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1mort2.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.d2)
		close_win(&vars);
	vars.player1.d3 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1mort3.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.d3)
		close_win(&vars);
	vars.player1.d4 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1mort4.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.d4)
		close_win(&vars);
	vars.player1.d5 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1mort5.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.d5)
		close_win(&vars);
	vars.player1.d6 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1mort6.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.d6)
		close_win(&vars);
	vars.player1.d7 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson1mort7.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.d7)
		close_win(&vars);
	vars.player2.d1 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2mort1.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.d1)
		close_win(&vars);
	vars.player2.d2 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2mort2.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.d2)
		close_win(&vars);
	vars.player2.d3 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2mort3.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.d3)
		close_win(&vars);
	vars.player2.d4 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2mort4.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.d4)
		close_win(&vars);
	vars.player2.d5 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2mort5.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.d5)
		close_win(&vars);
	vars.player2.d6 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2mort6.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.d6)
		close_win(&vars);
	vars.player2.d7 = mlx_xpm_file_to_image(vars.mlx, "xpm/Poisson2mort7.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.d7)
		close_win(&vars);
	init_map(&vars);
	init_zone(&vars);
	vars.player1.x = vars.p_pos.y * 65;
	vars.player1.y = vars.p_pos.x * 65;
	vars.player2.x = vars.p_pos.y * 65;
	vars.player2.y = vars.p_pos.x * 65;
	vars.player3.x = vars.e_pos.y * 65;
	vars.player3.y = vars.e_pos.x * 65;
	vars.update_counter = 101;
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_loop(vars.mlx);
	split_cleaner(&vars);
}

