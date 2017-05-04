/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:39:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 19:58:02 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_debug.h"

static void	do_memcpy(void *dst, const void *src, size_t n)
{
	while (n)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		++dst;
		++src;
		--n;
	}
}

#ifndef FT_MEM_OPT

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	FT_ASSERT(dst != NULL || n == 0);
	FT_ASSERT(src != NULL || n == 0);
	do_memcpy(dst, src, n);
	return (dst);
}

#else

static void	opt_memcpy(void *dst, const void *src, size_t n)
{
	while (FT_MEM_ALIGN(dst))
	{
		if (!n)
			return ;
		*((unsigned char *)dst) = *((unsigned char *)src);
		++dst;
		++src;
		--n;
	}
	while (n >= FT_MEM_WORDLEN)
	{
		*((t_mem_word *)dst) = *((t_mem_word *)src);
		dst += FT_MEM_WORDLEN;
		src += FT_MEM_WORDLEN;
		n -= FT_MEM_WORDLEN;
	}
	do_memcpy(dst, src, n);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	FT_ASSERT(dst != NULL || n == 0);
	FT_ASSERT(src != NULL || n == 0);
	if (FT_MEM_ALIGN(dst) == FT_MEM_ALIGN(src))
		opt_memcpy(dst, src, n);
	else
		do_memcpy(dst, src, n);
	return (dst);
}

#endif
