/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:22:49 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/26 15:12:10 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	where_to_go(int keycode, t_data *dt)
{
	if (keycode == ESC)
		exit_game(dt);
	else if (keycode == W_KEY)
		straight_move(dt);
	else if (keycode == A_KEY)
		left_move(dt);
	else if (keycode == S_KEY)
		back_move(dt);
	else if (keycode == D_KEY)
		right_move(dt);
	else if (keycode == LEFT_KEY)
		rot_left(dt);
	else if (keycode == RIGHT_KEY)
		rot_right(dt);
	return (EXIT_SUCCESS);
}

int	straight_move(t_data *dt)
{
	float	pos_x;
	float	pos_y;

	pos_x = dt->ppos_x + dt->pdir_x * SPEED;
	pos_y = dt->ppos_y + dt->pdir_y * SPEED;
	if (dt->map[(int)pos_y][(int)pos_x] == '1')
		return (0);
	dt->ppos_x += dt->pdir_x * SPEED;
	dt->ppos_y += dt->pdir_y * SPEED;
	return (0);
}

int	left_move(t_data *dt)
{
	float	pos_x;
	float	pos_y;

	pos_x = dt->ppos_x + dt->pdir_y * SPEED;
	pos_y = dt->ppos_y - dt->pdir_x * SPEED;
	if (dt->map[(int)pos_y][(int)pos_x] == '1')
		return (0);
	dt->ppos_x += dt->pdir_y * SPEED;
	dt->ppos_y -= dt->pdir_x * SPEED;
	return (0);
}

int	back_move(t_data *dt)
{
	float	pos_x;
	float	pos_y;

	pos_x = dt->ppos_x - dt->pdir_x * SPEED;
	pos_y = dt->ppos_y - dt->pdir_y * SPEED;
	if (dt->map[(int)pos_y][(int)pos_x] == '1')
		return (0);
	dt->ppos_x -= dt->pdir_x * SPEED;
	dt->ppos_y -= dt->pdir_y * SPEED;
	return (0);
}

int	right_move(t_data *dt)
{
	float	pos_x;
	float	pos_y;

	pos_x = dt->ppos_x - dt->pdir_y * SPEED;
	pos_y = dt->ppos_y + dt->pdir_x * SPEED;
	if (dt->map[(int)pos_y][(int)pos_x] == '1')
		return (0);
	dt->ppos_x -= dt->pdir_y * SPEED;
	dt->ppos_y += dt->pdir_x * SPEED;
	return (0);
}
