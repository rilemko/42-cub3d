/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/26 16:12:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_key_clear(void *key)
{
	ft_free((void *) key);
}

void	st_key_initialize(t_key *key)
{
	key->callback = NULL;
	key->code = 0;
	key->is_pressed = FALSE;
}
