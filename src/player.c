/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:33:33 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/31 15:12:32 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_display(t_data *dt)
{
	pixel_player(dt);
	ray_display(dt);
}

void	pixel_player(t_data *dt)
{
	int	pos_x;
	int	pos_y;

	pos_y = ((dt->ppos_y - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 3);
	while (pos_y < ((dt->ppos_y - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 7))
	{
		pos_x = ((dt->ppos_x - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 3);
		while (pos_x < ((dt->ppos_x - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 7))
		{
			my_pixel(dt, pos_x, pos_y, RED);
			pos_x++;
		}
		pos_y++;
	}
}

int	move_start(t_data *dt, float dist)
{
	float	olddirx;
	float	oldplane_x;

	olddirx = dt->pdir_x;
	oldplane_x = dt->ray->plane_x;
	dt->pdir_x = dt->pdir_x * cos(dist) - dt->pdir_y * sin(dist);
	dt->pdir_y = olddirx * sin(dist) + dt->pdir_y * cos(dist);
	dt->ray->plane_x = dt->ray->plane_x * cos(dist)
		- dt->ray->plane_y * sin(dist);
	dt->ray->plane_y = oldplane_x * sin(dist) + dt->ray->plane_y * cos(dist);
	return (0);
}

void	init_dir_player(t_data *dt)
{
	dt->pdir_x = 0;
	dt->pdir_y = -1;
	if (dt->player_direction == 'N')
		move_start(dt, 0);
	if (dt->player_direction == 'S')
		move_start(dt, (M_PI));
	if (dt->player_direction == 'W')
		move_start(dt, -(M_PI / 2));
	if (dt->player_direction == 'E')
		move_start(dt, (M_PI / 2));
}

void	ray_display(t_data *dt)
{
	float	pos_x;
	float	pos_y;
	int		i;

	i = 0;
	pos_x = dt->ppos_x + dt->pdir_x * SPEED;
	pos_y = dt->ppos_y + dt->pdir_y * SPEED;
	while (i < 10)
	{
		pos_x += dt->pdir_x * SPEED;
		pos_y += dt->pdir_y * SPEED;
		if (dt->map[(int)pos_y][(int)pos_x] == '1')
			return ;
		my_pixel(dt, pos_x * MAP_SIZE, pos_y * MAP_SIZE, GREEN);
		i++;
	}
}
