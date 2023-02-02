/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:38:34 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/30 20:39:03 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab != NULL && tab[len] != NULL)
	{
		free(tab[len]);
		len++;
	}
	free(tab);
	return (0);
}
