/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:42:42 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 21:40:06 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

static void	do_strcpy(char *dst, const char *src)
{
	while ((*dst = *src))
	{
		++dst;
		++src;
	}
}

#ifndef FT_MEM_OPT

char		*ft_strcpy(char *dst, const char *src)
{
	FT_ASSERT(dst != NULL);
	FT_ASSERT(src != NULL);
	do_strcpy(dst, src);
	return (dst);
}

#else

char		*ft_strcpy(char *dst, const char *src)
{
	char	*ret;

	FT_ASSERT(dst != NULL);
	FT_ASSERT(src != NULL);
	ret = dst;
	while (FT_MEM_ALIGN(src))
	{
		if (!(*dst = *src))
			return (ret);
		++dst;
		++src;
	}
	while (!FT_MEM_HASZERO(*((t_mem_word *)src)))
	{
		*((t_mem_word *)dst) = *((t_mem_word *)src);
		src += FT_MEM_WORDLEN;
		dst += FT_MEM_WORDLEN;
	}
	do_strcpy(dst, src);
	return (ret);
}

#endif
