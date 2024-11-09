/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 15:46:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_arg_clear(t_arg *arg)
{
	(void) arg;
}

void	st_arg_initialize(t_arg *arg, char **agv, char **env)
{
	arg->agv = agv;
	arg->env = env;
}
