/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:13:40 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/23 17:25:23 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rot_left(t_data *dt)
{
	float	oldpdir_x;
	float	oldplane_x;

	oldpdir_x = dt->pdir_x;
	oldplane_x = dt->ray->plane_x;
	dt->pdir_x = dt->pdir_x * cos(-ROT_SPEED) - dt->pdir_y * sin(-ROT_SPEED);
	dt->pdir_y = oldpdir_x * sin(-ROT_SPEED) + dt->pdir_y * cos(-ROT_SPEED);
	dt->ray->plane_x = dt->ray->plane_x * cos(-ROT_SPEED)
		- dt->ray->plane_y * sin(-ROT_SPEED);
	dt->ray->plane_y = oldplane_x * sin(-ROT_SPEED)
		+ dt->ray->plane_y * cos(-ROT_SPEED);
}

void	rot_right(t_data *dt)
{
	float	oldpdir_x;
	float	oldplane_x;

	oldpdir_x = dt->pdir_x;
	oldplane_x = dt->ray->plane_x;
	dt->pdir_x = dt->pdir_x * cos(ROT_SPEED) - dt->pdir_y * sin(ROT_SPEED);
	dt->pdir_y = oldpdir_x * sin(ROT_SPEED) + dt->pdir_y * cos(ROT_SPEED);
	dt->ray->plane_x = dt->ray->plane_x * cos(ROT_SPEED)
		- dt->ray->plane_y * sin(ROT_SPEED);
	dt->ray->plane_y = oldplane_x * sin(ROT_SPEED)
		+ dt->ray->plane_y * cos(ROT_SPEED);
}
