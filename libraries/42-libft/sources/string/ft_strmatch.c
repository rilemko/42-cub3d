/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:07:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/19 17:18:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_rt	ft_process(const char *pattern, const char *content,
				t_bool leading_wildcard);

t_bool	ft_strmatch(const char *pattern, const char *content)
{
	t_bool	leading_wildcard;

	leading_wildcard = FALSE;
	if (*pattern == '*')
	{
		leading_wildcard = TRUE;
		while (*pattern == '*')
		{
			if (*pattern++ == '\0')
				return (TRUE);
		}
		while (*content != *pattern)
		{
			if (*content++ == '\0')
				return (FALSE);
		}
	}
	return (ft_process(pattern, content, leading_wildcard));
}

static t_rt	ft_process(const char *pattern, const char *content,
	t_bool leading_wildcard)
{
	const char	*temp_pattern;

	temp_pattern = pattern;
	while (*content)
	{
		if (*pattern == '*')
			return (ft_strmatch(pattern, content));
		if (*content != *pattern)
		{
			if (ft_strpos(content, temp_pattern[0]) != FAILURE
				&& leading_wildcard == TRUE)
				return (ft_strmatch(temp_pattern, ft_strchr(content,
							temp_pattern[0])));
			return (FALSE);
		}
		content++;
		pattern++;
	}
	while (*pattern != '\0')
		if (*pattern++ != '*')
			return (FALSE);
	return (TRUE);
}
