/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:44:21 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/31 15:44:43 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_assets(t_asset *asset)
{
	asset->no = ft_calloc(1, sizeof(t_img));
	asset->so = ft_calloc(1, sizeof(t_img));
	asset->ea = ft_calloc(1, sizeof(t_img));
	asset->we = ft_calloc(1, sizeof(t_img));
}

void	text_init(t_data *dt)
{
	dt->asset->no->img = mlx_xpm_file_to_image(dt->mlx,
			dt->asset->no->img_path, &dt->asset->no->img_width,
			&dt->asset->no->img_height);
	dt->asset->no->pxs = (int *)mlx_get_data_addr(dt->asset->no->img,
			&dt->asset->no->bits, &dt->asset->no->s_line, &dt->asset->no->end);
	dt->asset->so->img = mlx_xpm_file_to_image(dt->mlx,
			dt->asset->so->img_path, &dt->asset->so->img_width,
			&dt->asset->so->img_height);
	dt->asset->so->pxs = (int *)mlx_get_data_addr(dt->asset->so->img,
			&dt->asset->so->bits, &dt->asset->so->s_line, &dt->asset->so->end);
	dt->asset->ea->img = mlx_xpm_file_to_image(dt->mlx,
			dt->asset->ea->img_path, &dt->asset->ea->img_width,
			&dt->asset->ea->img_height);
	dt->asset->ea->pxs = (int *)mlx_get_data_addr(dt->asset->ea->img,
			&dt->asset->ea->bits, &dt->asset->ea->s_line, &dt->asset->ea->end);
	dt->asset->we->img = mlx_xpm_file_to_image(dt->mlx,
			dt->asset->we->img_path, &dt->asset->we->img_width,
			&dt->asset->we->img_height);
	dt->asset->we->pxs = (int *)mlx_get_data_addr(dt->asset->we->img,
			&dt->asset->we->bits, &dt->asset->we->s_line, &dt->asset->we->end);
}

int	which_texture(t_data *dt, int i)
{
	if (dt->ray->side == 0 && dt->ray->ray_dir_x > 0)
		return (dt->asset->no->pxs[(int)i]);
	if (dt->ray->side == 0 && dt->ray->ray_dir_x <= 0)
		return (dt->asset->so->pxs[(int)i]);
	if (dt->ray->side == 1 && dt->ray->ray_dir_y <= 0)
		return (dt->asset->ea->pxs[(int)i]);
	else
		return (dt->asset->we->pxs[(int)i]);
	return (0);
}

int	where_texture(t_data *dt, t_ray *ray)
{
	ray->width = dt->asset->no->img_width;
	ray->height = dt->asset->no->img_height;
	if (ray->side == 0)
		ray->wall_x = dt->ppos_y + (ray->perp_wall_dist * ray->ray_dir_y);
	else
		ray->wall_x = dt->ppos_x + (ray->perp_wall_dist * ray->ray_dir_x);
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)ray->width);
	if (ray->side == 0 && ray->ray_dir_x <= 0)
		ray->tex_x = ray->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y >= 0)
		ray->tex_x = ray->width - ray->tex_x - 1;
	return (0);
}

void	put_texture(t_data *dt, t_ray *ray, int x)
{
	int		start;
	int		color;
	double	step;
	float	px;

	start = dt->line->drawstart;
	where_texture(dt, ray);
	step = 1.0 * ray->height / dt->line->height;
	ray->tex_pos = (dt->line->drawstart
			- (WIN_Y / 2) + dt->line->height / 2) * step;
	while (start < dt->line->drawend)
	{
		ray->tex_y = (int)ray->tex_pos & (ray->height - 1);
		ray->tex_pos += step;
		px = (ray->height * (ray->tex_y) + ray->tex_x);
		color = which_texture(dt, px);
		my_pixel(dt, x, start, color);
		start++;
	}
}
