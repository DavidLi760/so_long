/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:08:40 by davli             #+#    #+#             */
/*   Updated: 2024/06/22 19:30:14 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

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
		if (vars->key_state[119] && vars->player1.y > 65)
		{
			vars->player1.y -= 1;
			printf("W, ");
			printf(" %d ", vars->player1.y);
		}
		if (vars->key_state[115] && vars->player1.y < 845)
		{
			vars->player1.y += 1;
			printf("S, ");
			printf(" %d ", vars->player1.y);
		}
		if (vars->key_state[97] && vars->player1.x > 65)
		{
			vars->player1.x -= 1;
			printf("A, ");
			printf(" %d ", vars->player1.x);
		}
		if (vars->key_state[100] && vars->player1.x < 1755)
		{
			vars->player1.x += 1;
			printf("D, ");
			printf(" %d ", vars->player1.x);
		}
		if (vars->key_state[65362] && vars->player2.y > 65)
		{
			vars->player2.y -= 1;
			printf("W, ");
			printf(" %d ", vars->player2.y);
		}
		if (vars->key_state[65364] && vars->player2.y < 845)
		{
			vars->player2.y += 1;
			printf("S, ");
			printf(" %d ", vars->player2.y);
		}
		if (vars->key_state[65361] && vars->player2.x > 65)
		{
			vars->player2.x -= 1;
			printf("A, ");
			printf(" %d ", vars->player2.x);
		}
		if (vars->key_state[65363] && vars->player2.x < 1755)
		{
			vars->player2.x += 1;
			printf("D, ");
			printf(" %d ", vars->player2.x);
		}
	vars->update_counter = 0;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player1.img, vars->player1.x, vars->player1.y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player2.img, vars->player2.x, vars->player2.y);
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

int	main(void)
{
	t_vars	vars;
	int		i;
	int		j = 0;

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
	vars.img = mlx_xpm_file_to_image(vars.mlx, "block.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img)
		exit(1);
	vars.player1.img = mlx_xpm_file_to_image(vars.mlx, "block.xpm", &vars.player1.x, &vars.player1.y);
	if (!vars.player1.img)
		exit (1);
	vars.player2.img = mlx_xpm_file_to_image(vars.mlx, "block.xpm", &vars.player2.x, &vars.player2.y);
	if (!vars.player2.img)
		exit (1);
	vars.player1.x = 65;
	vars.player1.y = 65;
	vars.player2.x = 1755;
	vars.player2.y = 845;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player1.img, vars.player1.x, vars.player1.y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player2.img, vars.player2.x, vars.player2.y);
	while (j < 15)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0 + j++ * 65);
	}
	j = 0;
	while (j < 15)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 1820, 0 + j++ * 65);
	}
	j = 0;
	while (j < 29)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0 + j++ * 65, 0);
	}
	j = 0;
	while (j < 29)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0 + j++ * 65, 910);
	}
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_loop(vars.mlx);
}
