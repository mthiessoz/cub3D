/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 17:44:11 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_virgule(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i + 1]))
	{
		if (line[i] == ',' && (line[i + 1]) == ',')
			return (1);
		i++;
	}
	return (0);
}

int	atoi_color(t_data *dt, char **color, char what)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (what == 'F')
		dt->floor = create_trgb(r, g, b);
	else
		dt->ceiling = create_trgb(r, g, b);
	return (0);
}

void	calloc_asset(t_data *dt)
{
	dt->map = ft_calloc(dt->len_map + 1, sizeof(char *));
	dt->asset->nswe = ft_calloc(dt->asset->nb_nswe + 1, sizeof(char *));
	dt->asset->color = ft_calloc(dt->asset->nb_color + 1, sizeof(char *));
}

void	error_color(char *line)
{
	if (check_virgule(line))
	{
		printf("Error: parsing color (,)\n");
		exit(0);
	}
}
