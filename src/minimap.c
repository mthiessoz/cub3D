/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:41:12 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/30 12:10:51 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	minimap_display(t_data *dt)
{
	int		i;
	int		j;

	i = 0;
	while (i < dt->len_map)
	{
		j = 0;
		while (j < ft_strlen(dt->map[i]))
		{
			minimap_printer(dt, j, i, dt->map[i][j]);
			j++;
		}
		i++;
	}
	player_display(dt);
	return (0);
}

void	minimap_printer(t_data *dt, int i, int j, char c)
{
	if (c == '1')
		my_square_pixel (dt, i, j, BLU);
	else if (c == '0')
		my_square_pixel(dt, i, j, GRE);
}

void	my_square_pixel(t_data *dt, int x, int y, int color)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * MAP_SIZE;
	while (pos_x < ((x + 1) * MAP_SIZE))
	{
		pos_y = y * MAP_SIZE;
		while (pos_y < ((y + 1) * MAP_SIZE))
		{
			my_pixel(dt, pos_x, pos_y, color);
			pos_y++;
		}
		pos_x++;
	}
}

void	my_pixel(t_data *dt, int x, int y, int color)
{
	char	*dst;

	dst = dt->img->path + (y * dt->img->line + x * (dt->img->bytes / 8));
	*(unsigned int *)dst = color;
}
