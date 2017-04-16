/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:53:37 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 19:53:43 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_debug.h"

static void	*do_memchr(const void *str, unsigned char c, size_t n)
{
	while (n)
	{
		if (*((unsigned char *)str) == c)
			return ((void *)str);
		++str;
		--n;
	}
	return (NULL);
}

#ifndef FT_MEM_OPT

void		*ft_memchr(const void *str, int c, size_t n)
{
	FT_ASSERT(str != NULL || n == 0);
	return (do_memchr(str, (unsigned char)c, n));
}

#else

void		*ft_memchr(const void *str, int c, size_t n)
{
	t_mem_word	word;

	FT_ASSERT(str != NULL || n == 0);
	c = (unsigned char)c;
	while (FT_MEM_ALIGN(str))
	{
		if (!n)
			return (NULL);
		if (*((unsigned char *)str) == c)
			return ((void *)str);
		++str;
		--n;
	}
	word = FT_MEM_WORD(c);
	while (n > FT_MEM_WORDLEN
		&& !FT_MEM_HASZERO(*((t_mem_word *)str) ^ word))
	{
		str += FT_MEM_WORDLEN;
		n -= FT_MEM_WORDLEN;
	}
	return (do_memchr(str, c, n));
}

#endif
