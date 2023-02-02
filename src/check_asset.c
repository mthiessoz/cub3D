/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:13 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 17:35:10 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_path(t_data *dt)
{
	int	fd;

	fd = open(dt->asset->path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: invalid path texture\n");
		close(fd);
		exit_more(dt);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	check_valid_path(t_data *dt, char *line)
{
	if (line && !ft_strncmp(line, "NO", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->no->img_path = ft_strdup(dt->asset->path);
	}
	else if (line && !ft_strncmp(line, "SO", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->so->img_path = ft_strdup(dt->asset->path);
	}
	check_valid_path2(dt, line);
	free(dt->asset->path);
	dt->asset->path = NULL;
	return (EXIT_SUCCESS);
}

void	check_valid_path2(t_data *dt, char *line)
{
	if (line && !ft_strncmp(line, "WE", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->we->img_path = ft_strdup(dt->asset->path);
	}
	else if (line && !ft_strncmp(line, "EA", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->ea->img_path = ft_strdup(dt->asset->path);
	}
}

int	check_color(t_data *dt, char *line)
{
	char	**tmp;
	char	*tmp_2;
	int		i;

	i = 0;
	error_color(line);
	tmp = ft_split(line + 1, ',');
	if (!tmp)
		printf("Error: in check color\n");
	while (i != 3 && tmp[i])
	{
		tmp_2 = tmp[i];
		tmp[i] = ft_strtrim(tmp_2, " ");
		free(tmp_2);
		i++;
	}
	check_nb_color(dt, tmp);
	if (!ft_strncmp(line, "F", 1))
		atoi_color(dt, tmp, 'F');
	else
		atoi_color(dt, tmp, 'C');
	free_tmp(tmp);
	return (0);
}

int	parse_color2(t_data *dt, char *line)
{
	int	i;

	i = 0;
	if (!ft_strncmp(&line[i], "F", 1) || !ft_strncmp(&line[i], "C", 1))
	{
		check_color(dt, &line[i]);
		i++;
	}
	return (0);
}
