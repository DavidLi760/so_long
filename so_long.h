/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:09:06 by davli             #+#    #+#             */
/*   Updated: 2024/06/20 21:32:29 by davli            ###   ########.fr       */
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

# define w 119
# define s 115
# define a 97
# define d 100

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	int	img_width;
	int	img_height;
	int	pos_x;
	int	pos_y;
	int	key_state[256];
	int	update_counter;
	int	mouse_pressed;

}	t_vars;

#endif
