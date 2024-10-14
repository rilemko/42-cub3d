/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/02 15:00:15 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_src	*ft_src_add(t_app *app, int code, const char *token,
	void (*callback)(t_app *, struct s_src *))
{
	t_src	*src;

	src = malloc(sizeof(t_src));
	if (src != NULL)
	{
		st_src_initialize(src);
		src->code = code;
		token = ft_strtrim(token, " ");
		ft_strlcpy(src->token, token, MAX_CODE_SIZE);
		ft_free((void *) token);
		src->callback = callback;
		ft_lstadd_back(&app->_srcs, ft_lstnew((void *) src));
		app->prs.count_total += 1;
	}
	return (src);
}
