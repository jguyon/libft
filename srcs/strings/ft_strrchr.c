/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:26:26 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 20:52:03 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

static char	*do_strrchr(const char *str, char c)
{
	char	*found;

	found = NULL;
	while (1)
	{
		if (*str == c)
			found = (char *)str;
		if (!(*str))
			return (found);
		++str;
	}
}

#ifndef FT_MEM_OPT

char		*ft_strrchr(const char *str, int c)
{
	FT_ASSERT(str != NULL);
	return (do_strrchr(str, (char)c));
}

#else

char		*ft_strrchr(const char *str, int c)
{
	char		*found;
	t_mem_word	word;

	FT_ASSERT(str != NULL);
	c = (char)c;
	found = NULL;
	while (FT_MEM_ALIGN(str))
	{
		if (*str == c)
			found = (char *)str;
		if (!(*str))
			return (found);
		++str;
	}
	word = FT_MEM_WORD(c);
	while (
		!FT_MEM_HASZERO(*((t_mem_word *)str) & (*((t_mem_word *)str) ^ word))
	)
		str += FT_MEM_WORDLEN;
	return (do_strrchr(str, c));
}

#endif
