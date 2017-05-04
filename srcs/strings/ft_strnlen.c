/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:17:56 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 20:38:16 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

static size_t	do_strnlen(const char *start, const char *end, size_t max)
{
	while (*end && max)
	{
		++end;
		--max;
	}
	return (end - start);
}

#ifndef FT_MEM_OPT

size_t			ft_strnlen(const char *str, size_t max)
{
	FT_ASSERT(str != NULL);
	return (do_strnlen(str, str, max));
}

#else

size_t			ft_strnlen(const char *str, size_t max)
{
	const char	*end;

	FT_ASSERT(str != NULL);
	end = str;
	while (FT_MEM_ALIGN(str))
	{
		if (!max || !(*end))
			return (end - str);
		++end;
		--max;
	}
	while (max > FT_MEM_WORDLEN && !FT_MEM_HASZERO(*((t_mem_word *)end)))
	{
		end += FT_MEM_WORDLEN;
		max -= FT_MEM_WORDLEN;
	}
	return (do_strnlen(str, end, max));
}

#endif
