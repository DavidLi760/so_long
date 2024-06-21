/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:09:06 by davli             #+#    #+#             */
/*   Updated: 2024/06/21 13:53:03 by davli            ###   ########.fr       */
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

# define W 119
# define S 115
# define A 97
# define D 100

typedef struct s_player
{
	int		x;
	int		y;
	int		power;
	void	*img;
	int		img_width;
	int		img_height;
}	t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	int			img_width;
	int			img_height;
	int			pos_x;
	int			pos_y;
	int			key_state[65365];
	int			update_counter;
	int			mouse_pressed;
	t_player	player1;
	t_player	player2;

}	t_vars;

#endif
