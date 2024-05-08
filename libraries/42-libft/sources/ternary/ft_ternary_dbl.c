/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary_dbl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:15:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 16:13:56 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	ft_ternary_dbl() :
*	Implements ternary operators. If { condition } is true, { then } returns,
*	otherwise { otherwise } returns.
*/
double	ft_ternary_dbl(int condition, double then, double otherwise)
{
	if (condition)
		return (then);
	return (otherwise);
}
