/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 15:58:16 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_key	*ft_key_add(t_app *app, int code, void (*callback)(t_app *, t_bool))
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (key != NULL)
	{
		st_key_initialize(key);
		key->code = code;
		key->callback = callback;
		ft_lstadd_back(&app->_keys, ft_lstnew((void *) key));
	}
	return (key);
}
