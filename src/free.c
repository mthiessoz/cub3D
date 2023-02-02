/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:27:04 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 16:09:34 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(tmp[i++]);
	}
	free(tmp);
}

void	check_nb_color(t_data *dt, char **tmp)
{
	if (ft_tablen(tmp) != 3 || !ft_tab_isnumber(tmp))
	{
		printf("Error : missing color\n");
		exit_more(dt);
	}
}
