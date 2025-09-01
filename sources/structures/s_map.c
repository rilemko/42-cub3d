/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/20 19:11:11 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_map_clear(t_map *map)
{
	ft_free_deep((void **) map->map);
}

void	st_map_initialize(t_map *map)
{
	ft_bzero(map->buffer, MAX_BUFF_SIZE);
	map->map = NULL;
	map->size_h = 0;
	map->size_w = 0;
}
