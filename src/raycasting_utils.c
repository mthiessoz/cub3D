/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:56:52 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/31 15:12:48 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	screen_display(t_data *dt)
{
	raycasting(dt);
	minimap_display(dt);
	mlx_put_image_to_window(dt->mlx, dt->window, dt->img->img, 0, 0);
	return (0);
}

void	hit_wall(t_data *dt)
{
	if (dt->map[dt->ray->map_y][dt->ray->map_x] != '0')
			dt->ray->hit = 1;
}

void	calcul_perp_distance(t_data *dt)
{
	if (dt->ray->side == 0)
	{
		dt->ray->perp_wall_dist = (dt->ray->side_dist_x
				- dt->ray->delta_dist_x);
	}
	else
	{
		dt->ray->perp_wall_dist = (dt->ray->side_dist_y
				- dt->ray->delta_dist_y);
	}
}

void	calcul_stripe_to_fill(t_data *dt)
{
	dt->line = malloc(sizeof(t_line));
	dt->line->height = (WIN_Y / dt->ray->perp_wall_dist);
	dt->line->drawstart = (dt->line->height / -2) + WIN_Y / 2;
	if (dt->line->drawstart < 0)
		dt->line->drawstart = 0;
	dt->line->drawend = (dt->line->height / 2) + WIN_Y / 2;
	if (dt->line->drawend >= WIN_Y)
		dt->line->drawend = WIN_Y - 1;
}

int	draw_ver_line(t_data *dt, int x)
{
	int	i;
	int	start;
	int	end;

	i = -1;
	start = dt->line->drawstart;
	end = dt->line->drawend;
	while (++i < start)
		my_pixel(dt, x, i, dt->ceiling);
	while (start < end)
		start++;
	while (start < (WIN_Y - 1))
	{
		my_pixel(dt, x, start, dt->floor);
		start++;
	}
	return (0);
}
