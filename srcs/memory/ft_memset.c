/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:57:32 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 20:01:58 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_debug.h"

static void	do_memset(void *str, unsigned char c, size_t n)
{
	while (n)
	{
		*((unsigned char *)str) = c;
		++str;
		--n;
	}
}

#ifndef FT_MEM_OPT

void		*ft_memset(void *str, int c, size_t n)
{
	FT_ASSERT(str || n == 0);
	do_memset(str, (unsigned char)c, n);
	return (str);
}

#else

void		*ft_memset(void *str, int c, size_t n)
{
	void		*ret;
	t_mem_word	word;

	FT_ASSERT(str || n == 0);
	ret = str;
	c = (unsigned char)c;
	while (FT_MEM_ALIGN(str))
	{
		if (!n)
			return (ret);
		*((unsigned char *)str) = c;
		++str;
		--n;
	}
	word = FT_MEM_WORD(c);
	while (n >= FT_MEM_WORDLEN)
	{
		*((t_mem_word *)str) = word;
		str += FT_MEM_WORDLEN;
		n -= FT_MEM_WORDLEN;
	}
	do_memset(str, c, n);
	return (ret);
}

#endif
