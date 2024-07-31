/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/27 01:39:16 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_mlx_clear(t_mlx *mlx)
{
	if (mlx->mlx != NULL)
		mlx_terminate(mlx->mlx);
}

void	st_mlx_initialize(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->timestamp = 0;
}
