/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:08:40 by davli             #+#    #+#             */
/*   Updated: 2024/06/25 22:03:27 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	else if (keycode >= 0 && keycode < 65365)
	{
		vars->key_state[keycode] = 1;
	}
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
	if (vars->update_counter >= 50)
	{
		if (vars->key_state[W] && vars->player1.y > 65)
		{
			vars->player1.y -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[S] && vars->player1.y < 845)
		{
			vars->player1.y += 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[A] && vars->player1.x > 65)
		{
			vars->player1.x -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_g, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[D] && vars->player1.x < 1755)
		{
			vars->player1.x += 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img_d, vars->player1.x, vars->player1.y);
		}
		if (vars->key_state[ARROW_UP] && vars->player2.y > 65)
		{
			vars->player2.y -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
		}
		if (vars->key_state[ARROW_DOWN] && vars->player2.y < 845)
		{
			vars->player2.y += 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
		}
		if (vars->key_state[ARROW_LEFT] && vars->player2.x > 65)
		{
			vars->player2.x -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img_g, vars->player2.x, vars->player2.y);
		}
		if (vars->key_state[ARROW_RIGHT] && vars->player2.x < 1755)
		{
			vars->player2.x += 1;
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
		exit(-9);
	vars->map_fd = open(argv[1], O_RDONLY);
	vars->map_buf = get_next_line(vars->map_fd);
	if (!vars->map_buf)
		return ;
	vars->map_line = ft_split(vars->map_buf, '\n');
	vars->map_temp = ft_split(vars->map_buf, '\n');
	map_error(argc, vars);
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
	vars.win = mlx_new_window(vars.mlx, 1890, 980, "so_long");
	if (vars.mlx == NULL)
	{
		free(vars.mlx);
		return (1);
	}
	i = 0;
	vars.update_counter = 0;
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
	vars.player1.img_d = mlx_xpm_file_to_image(vars.mlx, "Poisson1d.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.img_d)
		exit (1);
	vars.player1.img_g = mlx_xpm_file_to_image(vars.mlx, "Poisson1g.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.img_g)
		exit (1);
	vars.player2.img_g = mlx_xpm_file_to_image(vars.mlx, "Poisson3g.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.img_g)
		exit (1);
	vars.player2.img_d = mlx_xpm_file_to_image(vars.mlx, "Poisson3d.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.img_d)
		exit (1);
	vars.player1.x = 65;
	vars.player1.y = 65;
	vars.player2.x = 1755;
	vars.player2.y = 845;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player1.img_g, vars.player1.x, vars.player1.y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player1.img_d, vars.player1.x, vars.player1.y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player2.img_d, vars.player2.x, vars.player2.y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player2.img_g, vars.player2.x, vars.player2.y);
	init_map(&vars);
	split_cleaner(&vars);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_loop(vars.mlx);
}
