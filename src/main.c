/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:44:44 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 16:48:32 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	ft_bzero(&dt, sizeof(t_data));
	error_args(argc, argv);
	init_game(&dt);
	init_asset(&dt);
	dt.map_path = ft_strdup(argv[1]);
	if (read_map(&dt) == EXIT_FAILURE)
	{
		ft_printf("Error\n");
		exit_game(&dt);
	}
	text_init(&dt);
	mlx_loop_hook(dt.mlx, screen_display, &dt);
	mlx_hook(dt.window, 2, 1L << 0, where_to_go, &dt);
	mlx_hook(dt.window, 17, 0, &exit_game, &dt);
	mlx_loop(dt.mlx);
	return (EXIT_SUCCESS);
}
