/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:08:40 by davli             #+#    #+#             */
/*   Updated: 2024/06/20 19:52:59 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	esc_window(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 119)
		printf("Touch pressed :%d, w", keycode);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
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

	vars.mouse_pressed = 0;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 2500, 1300, "so_long");
	if (vars.mlx == NULL)
	{
		free(vars.mlx);
		return (1);
	}
	vars.img = mlx_xpm_file_to_image(vars.mlx, "block.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img)
		exit(1);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 100, 100);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 50,150);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_hook(vars.win, 2, 1L << 0, esc_window, &vars);
	mlx_loop(vars.mlx);
}
