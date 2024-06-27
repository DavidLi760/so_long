/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:09:06 by davli             #+#    #+#             */
/*   Updated: 2024/06/27 15:51:36 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "stddef.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define MAX_MAP 100
# define W 119
# define S 115
# define A 97
# define D 100
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

typedef struct s_map
{
	int		width;
	int		height;
	char	map[MAX_MAP][MAX_MAP];
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		power;
	void	*img_d;
	void	*img_g;
	int		img_width;
	int		img_height;
}	t_player;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img0;
	void		*img1;
	void		*imgC;
	char		*map_buf;
	char		**map_line;
	char		**map_temp;
	int			map_fd;
	int			map_x;
	int			map_y;
	int			map_width;
	int			map_height;
	int			map_pixel[1890][980];
	int			e_count;
	int			p_count;
	int			c_count;
	int			img_width;
	int			img_height;
	int			pos_x;
	int			pos_y;
	int			key_state[65365];
	int			update_counter;
	int			mouse_pressed;
	t_pos		p_pos;
	t_pos		e_pos;
	t_player	player1;
	t_player	player2;

}	t_vars;

int		check_opening(char *argv, t_vars *vars);
int		check_rectangular(t_vars *vars);
int		is_closed(t_vars *vars);
void	get_map_pos(t_vars *vars);
void	map_error(int argc, t_vars *vars);
int		flood_fill(t_vars *vars);
int		check_correct_char(t_vars *vars);
void	split_cleaner(t_vars *vars);
void	exit_error(int error, t_vars *vars);
void	check_arg(t_vars *vars, int argc, char **argv);
void	init_map(t_vars *vars);

#endif
