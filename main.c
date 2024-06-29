/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:08:40 by davli             #+#    #+#             */
/*   Updated: 2024/06/29 15:06:58 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img0)
		mlx_destroy_image(vars->mlx, vars->img0);
	if (vars->img1)
		mlx_destroy_image(vars->mlx, vars->img1);
	if (vars->imgC)
		mlx_destroy_image(vars->mlx, vars->imgC);
	if (vars->imgE)
		mlx_destroy_image(vars->mlx, vars->imgE);
	if (vars->player1.img_d)
		mlx_destroy_image(vars->mlx, vars->player1.img_d);
	if (vars->player1.img_g)
		mlx_destroy_image(vars->mlx, vars->player1.img_g);
	if (vars->player2.img_d)
		mlx_destroy_image(vars->mlx, vars->player2.img_d);
	if (vars->player2.img_g)
		mlx_destroy_image(vars->mlx, vars->player2.img_g);
	if (vars->mlx)
		free(vars->mlx);
	exit (0);
	return (0);
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

int	update(t_vars *vars)
{
	vars->update_counter++;
	if (vars->update_counter >= 150)
	{
		if (vars->key_state[W] && vars->map_pixel[vars->player1.y - 1][vars->player1.x] != 1)
		{
			vars->player1.y -= 1;
			//			printf("Y%d, ", vars->player1.y);
			if (vars->key_state[D])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
			else if (vars->key_state[A])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[S] && vars->map_pixel[vars->player1.y + 1][vars->player1.x] != 1)
		{
			vars->player1.y += 1;
			//			printf("Y%d, ", vars->player1.y);
			if (vars->key_state[D])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
			else if (vars->key_state[A])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[A] && vars->map_pixel[vars->player1.y][vars->player1.x - 1] != 1)
		{
			vars->player1.x -= 1;
			//			printf("X%d, ", vars->player1.x);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[D] && vars->map_pixel[vars->player1.y][vars->player1.x + 1] != 1)
		{
			vars->player1.x += 1;
			//			printf("X%d, ", vars->player1.x);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[ARROW_UP] && vars->map_pixel[vars->player2.y - 1][vars->player2.x] != 1)
		{
			vars->player2.y -= 1;
			//			printf("Y%d, ", vars->player2.y);
			if (vars->key_state[ARROW_RIGHT])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_d, vars->player2.x, vars->player2.y);
			else if (vars->key_state[ARROW_LEFT])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
		}
		if (vars->key_state[ARROW_DOWN] && vars->map_pixel[vars->player2.y + 1][vars->player2.x] != 1)
		{
			vars->player2.y += 1;
			//			printf("Y%d, ", vars->player2.y);
			if (vars->key_state[ARROW_RIGHT])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_d, vars->player2.x, vars->player2.y);
			else if (vars->key_state[ARROW_LEFT])
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
		}
		if (vars->key_state[ARROW_LEFT] && vars->map_pixel[vars->player2.y][vars->player2.x - 1] != 1)
		{
			vars->player2.x -= 1;
			//			printf("X%d, ", vars->player2.x);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
		}
		if (vars->key_state[ARROW_RIGHT] && vars->map_pixel[vars->player2.y][vars->player2.x + 1] != 1)
		{
			vars->player2.x += 1;
			//			printf("X%d, ", vars->player2.x);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_d, vars->player2.x, vars->player2.y);
		}
		vars->update_counter = 0;
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->mouse_pressed = 1;
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0x0000FF);
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->mouse_pressed = 0;
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0x000000);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->mouse_pressed == 1)
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0x0000FF);
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
		exit (-1);
	vars->map_line = ft_split(vars->map_buf, '\n');
	vars->map_temp = ft_split(vars->map_buf, '\n');
	map_error(vars);
	printf("Success\n");
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
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgC, j * 65, i * 65);
			if (vars->map_line[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, j * 65, i * 65);
			if (vars->map_line[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgE, j * 65, i * 65);
			j++;
		}
		i++;
	}
}

void	init_forbidden_zone(t_vars *vars, int i, int j)
{
	int	forbidden;
	int		temp_i;
	int		temp_j;

	if (vars->map_line[i][j] == '1' || vars->map_line[i][j] == 'E')
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

void	forbidden_zone(t_vars *vars)
{
	int	i;
	int	j;

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
	int		i;

	vars.c_count = 0;
	vars.e_count = 0;
	vars.p_count = 0;
	check_arg(&vars, argc, argv);
	vars.mouse_pressed = 0;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 1885, 975, "so_long");
	if (vars.mlx == NULL)
	{
		free(vars.mlx);
		return (1);
	}
	i = 0;
	while (i < 65365)
		vars.key_state[i++] = 0;
	vars.img0 = mlx_xpm_file_to_image(vars.mlx, "Eau.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img0)
		exit(1);
	vars.img1 = mlx_xpm_file_to_image(vars.mlx, "Wall.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img1)
		exit(1);
	vars.imgC = mlx_xpm_file_to_image(vars.mlx, "Wall.xpm", &vars.img_width, &vars.img_height);
	if (!vars.imgC)
		exit(1);
	vars.imgE = mlx_xpm_file_to_image(vars.mlx, "PortalClose.xpm", &vars.img_width, &vars.img_height);
	if (!vars.imgC)
		exit(1);
	vars.player1.img_d = mlx_xpm_file_to_image(vars.mlx, "Poisson1d.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.img_d)
		exit (1);
	vars.player1.img_g = mlx_xpm_file_to_image(vars.mlx, "Poisson1g.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.img_g)
		exit (1);
	vars.player2.img_g = mlx_xpm_file_to_image(vars.mlx, "Poisson2g.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.img_g)
		exit (1);
	vars.player2.img_d = mlx_xpm_file_to_image(vars.mlx, "Poisson2d.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.img_d)
		exit (1);
	vars.player1.x = vars.p_pos.x * 65;
	vars.player1.y = vars.p_pos.y * 65;
	vars.player2.x = vars.p_pos.x * 65;
	vars.player2.y = vars.p_pos.y * 65;
	//	mlx_put_image_to_window(vars.mlx, vars.win, vars.player1.img_g, vars.player1.x, vars.player1.y);
	//	mlx_put_image_to_window(vars.mlx, vars.win, vars.player1.img_d, vars.player1.x, vars.player1.y);
	//	mlx_put_image_to_window(vars.mlx, vars.win, vars.player2.img_d, vars.player2.x, vars.player2.y);
	//	mlx_put_image_to_window(vars.mlx, vars.win, vars.player2.img_g, vars.player2.x, vars.player2.y);
	init_map(&vars);
	forbidden_zone(&vars);
	split_cleaner(&vars);
	vars.update_counter = 101;
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_loop(vars.mlx);
}

