/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:04 by davli             #+#    #+#             */
/*   Updated: 2024/06/22 18:12:25 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	char *buf;
	printf("%d\n", fd);
	while (buf)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		printf("%s", buf);
	}
	return (0);
}
