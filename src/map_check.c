/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 17:54:27 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_map_char(t_data *dt)
{
	int	x;
	int	y;

	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			if (dt->map[y][x] != '1' && dt->map[y][x] != '0'
				&& dt->map[y][x] != 'N' && dt->map[y][x] != 'S'
				&& dt->map[y][x] != 'E' && dt->map[y][x] != 'W'
				&& dt->map[y][x] != ' ')
			{
				printf("Error: Invalid character\n");
				exit_more(dt);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	check_borders_debut(t_data *dt)
{
	int	j;

	j = 0;
	while (dt->map[0][j])
	{
		if (dt->map[0][j] != '1')
		{
			printf("Error: Wall error\n");
			exit_more(dt);
		}
		if (ft_strlen(dt->map[0])
			< ft_strlen(dt->map[1]))
		{
			printf("Error: Wall error\n");
			exit_more(dt);
		}	
		j++;
	}
}

int	check_borders(t_data *dt)
{
	int	j;

	empty_map(dt);
	check_borders_debut(dt);
	j = 0;
	while (dt->map[dt->map_height - 1][j])
	{
		if (ft_strlen(dt->map[dt->map_height - 1])
			< ft_strlen(dt->map[dt->map_height - 2]))
		{
			printf("Error: Wall error\n");
			exit_more(dt);
		}	
		if (dt->map[dt->map_height - 1][j] != '1')
		{
			printf("Error: Wall error\n");
			exit_more(dt);
		}
		j++;
	}
	check_borders_la_suite(dt);
	return (0);
}

void	check_borders_la_suite(t_data *dt)
{
	int	i;

	i = 0;
	while (dt->map[i])
	{
		if (dt->map[i][0] != '1'
			|| dt->map[i][ft_strlen(dt->map[i]) - 1] != '1')
		{
			printf("Error: Wall error\n");
			exit_more(dt);
		}
		i++;
	}
}

int	check_player(t_data *dt)
{
	int	x;
	int	y;

	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			if (dt->map[y][x] == 'N' || dt->map[y][x] == 'S'
				|| dt->map[y][x] == 'W' || dt->map[y][x] == 'E')
			{
				dt->player_count++;
				multiple_players(dt);
				dt->ppos_x = x + 0.5;
				dt->ppos_y = y + 0.5;
				dt->player_direction = dt->map[y][x];
				dt->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	no_player(dt);
	return (0);
}
