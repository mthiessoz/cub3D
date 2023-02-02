/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:51:09 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 15:29:45 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	error_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error :\nWrong number of arguments\n");
		exit (EXIT_FAILURE);
	}
	if (check_cub(argv[1]) != 1)
	{
		ft_printf("Error :\nWrong map, please insert a .cub map\n");
		exit (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error :\nThis file doesn't exist\n");
		exit (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_cub(char *c)
{
	int	i;

	i = ft_strlen(c);
	if (c[--i] == 'b')
	{
		if (c[--i] == 'u')
		{
			if (c[--i] == 'c')
				return (1);
		}
	}
	return (EXIT_SUCCESS);
}
