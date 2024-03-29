/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:13:06 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 20:47:36 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

static char	*do_strchr(const char *str, char c)
{
	while (*str != c)
	{
		if (!(*str))
			return (NULL);
		++str;
	}
	return ((char *)str);
}

#ifndef FT_MEM_OPT

char		*ft_strchr(const char *str, int c)
{
	FT_ASSERT(str != NULL);
	return (do_strchr(str, (char)c));
}

#else

char		*ft_strchr(const char *str, int c)
{
	t_mem_word	word;

	FT_ASSERT(str != NULL);
	c = (char)c;
	while (FT_MEM_ALIGN(str))
	{
		if (*str == c)
			return ((char *)str);
		if (!(*str))
			return (NULL);
		++str;
	}
	word = FT_MEM_WORD(c);
	while (
		!FT_MEM_HASZERO(*((t_mem_word *)str) & (*((t_mem_word *)str) ^ word))
	)
		str += FT_MEM_WORDLEN;
	return (do_strchr(str, c));
}

#endif
