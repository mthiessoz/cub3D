/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:51:50 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/31 16:52:26 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	nb_of_asset(char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		printf("Error : %s\n", line);
		return (EXIT_FAILURE);
	}
	while (line[i] != '\0')
	{
		if (ft_strchr("NSWE", line[i]))
			return (1);
		else if (ft_strchr("FC", line[i]))
			return (2);
		else if (ft_strchr("01", line[i]))
			return (3);
		i++;
	}
	return (0);
}

int	nb_line(t_data *dt, int number, int fd)
{
	int		i;
	char	*tmp;
	int		type;

	i = 0;
	type = 0;
	if (number == -1)
		return (EXIT_FAILURE);
	fd = open(dt->map_path, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (nb_of_asset(tmp) == number)
			type++;
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		i++;
	}
	dt->nb_line = i;
	close(fd);
	return (type);
}

int	read_map(t_data *dt)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	fd = open(dt->map_path, O_RDONLY);
	init_file(dt, fd);
	error_map(dt, fd);
	asset_utils(dt);
	while (i < dt->nb_line)
	{
		line = get_next_line(fd);
		tmp = line;
		line = ft_strtrim(line, "\n\t ");
		free(tmp);
		if (!line)
			break ;
		else if (nb_of_asset(line) != 0)
			i = parse_file(dt, line, i);
		free (line);
	}
	close(fd);
	read_map_utils(dt);
	return (EXIT_SUCCESS);
}

int	read_map_utils(t_data *dt)
{
	check_borders(dt);
	check_map_char(dt);
	check_player(dt);
	replace_space_by_wall(dt);
	init_dir_player(dt);
	return (EXIT_SUCCESS);
}

int	error_map(t_data *dt, int fd)
{
	if (dt->nb_line == 0)
	{
		ft_printf("Error\n");
		exit_more(dt);
	}
	if (fd == -1)
	{
		ft_printf("Error:\n map error\n");
		exit_more(dt);
	}
	return (0);
}
