/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:32:40 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 20:29:22 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

static size_t	do_strlen(const char *start, const char *end)
{
	while (*end)
		++end;
	return (end - start);
}

#ifndef FT_MEM_OPT

size_t			ft_strlen(const char *str)
{
	FT_ASSERT(str != NULL);
	return (do_strlen(str, str));
}

#else

size_t			ft_strlen(const char *str)
{
	const char	*end;

	FT_ASSERT(str != NULL);
	end = str;
	while (FT_MEM_ALIGN(end))
	{
		if (!(*end))
			return (end - str);
		++end;
	}
	while (!FT_MEM_HASZERO(*((t_mem_word *)end)))
		end += FT_MEM_WORDLEN;
	return (do_strlen(str, end));
}

#endif
