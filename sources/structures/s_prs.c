/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_prs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/26 16:21:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_prs_clear(t_prs *prs)
{
	st_sts_clear(&prs->sts);
	st_ptr_clear(&prs->ptr);
	st_lne_clear(&prs->old);
	st_lne_clear(&prs->nxt);
	st_lne_clear(&prs->new);
}

void	st_prs_initialize(t_prs *prs)
{
	prs->count_index = 0;
	prs->count_total = 0;
	prs->is_complete = FALSE;
	st_lne_initialize(&prs->new);
	st_lne_initialize(&prs->nxt);
	st_lne_initialize(&prs->old);
	st_ptr_initialize(&prs->ptr);
	st_sts_initialize(&prs->sts);
}
