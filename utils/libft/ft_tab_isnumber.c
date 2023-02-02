/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_isnumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:29:32 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/12 15:33:59 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_isnumber(char **tab)
{
	int	i;

	i = -1;
	while (++i < ft_tablen(tab))
	{
		if (!ft_isnumber(tab[i]))
			return (0);
	}
	return (1);
}
