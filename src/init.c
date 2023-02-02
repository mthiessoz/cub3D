/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:05:46 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/30 20:28:05 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(t_data *dt)
{
	dt->ray = ft_calloc(1, sizeof(t_ray));
	dt->img = ft_calloc(1, sizeof(t_imgptr));
	dt->mlx = mlx_init();
	dt->window = mlx_new_window(dt->mlx, WIN_X, WIN_Y, "Les gentils seaux");
	dt->img->img = mlx_new_image(dt->mlx, WIN_X, WIN_Y);
	dt->img->path = mlx_get_data_addr(dt->img->img, &dt->img->bytes,
			&dt->img->line, &dt->img->end);
	dt->tablen = 0;
	dt->player_count = 0;
	dt->ppos_x = 0;
	dt->ppos_y = 0;
	dt->ray->plane_x = 0.66;
	dt->ray->plane_y = 0;
	return (0);
}

int	init_asset(t_data *dt)
{
	dt->asset = ft_calloc(1, sizeof(t_asset));
	dt->asset->path = NULL;
	dt->asset->nb_color = 0;
	dt->asset->nb_nswe = 0;
	init_assets(dt->asset);
	return (0);
}

void	init_file(t_data *dt, int fd)
{
	dt->asset->nb_nswe = nb_line(dt, 1, fd);
	dt->asset->nb_color = nb_line(dt, 2, fd);
	dt->len_map = nb_line(dt, 3, fd);
}

void	init_map(t_data *dt)
{
	int	len;

	dt->map_height = 0;
	dt->map_width = 0;
	while (dt->map[dt->map_height])
	{
		len = ft_strlen(dt->map[dt->map_height]);
		if (len > dt->map_width)
			dt->map_width = len;
		dt->map_height++;
	}
}
