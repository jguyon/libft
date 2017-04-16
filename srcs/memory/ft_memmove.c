/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:24:14 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 19:51:02 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_debug.h"

#ifndef FT_MEM_OPT

static void	cpy_left(void *dst, const void *src, size_t n)
{
	while (n)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		++dst;
		++src;
		--n;
	}
}

static void	cpy_right(void *dst, const void *src, size_t n)
{
	while (n)
	{
		--dst;
		--src;
		*((unsigned char *)dst) = *((unsigned char *)src);
		--n;
	}
}

#else

static void	cpy_left(void *dst, const void *src, size_t n)
{
	if (FT_MEM_ALIGN(dst) == FT_MEM_ALIGN(src))
	{
		while (FT_MEM_ALIGN(dst) && n)
		{
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
	}
	while (n)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		++dst;
		++src;
		--n;
	}
}

static void	cpy_right(void *dst, const void *src, size_t n)
{
	if (FT_MEM_ALIGN(dst) == FT_MEM_ALIGN(src))
	{
		while (FT_MEM_ALIGN(dst) && n)
		{
			--dst;
			--src;
			*((unsigned char *)dst) = *((unsigned char *)src);
			--n;
		}
		while (n >= FT_MEM_WORDLEN)
		{
			dst -= FT_MEM_WORDLEN;
			src -= FT_MEM_WORDLEN;
			*((t_mem_word *)dst) = *((t_mem_word *)src);
			n -= FT_MEM_WORDLEN;
		}
	}
	while (n)
	{
		--dst;
		--src;
		*((unsigned char *)dst) = *((unsigned char *)src);
		--n;
	}
}

#endif

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	FT_ASSERT(dst != NULL || len == 0);
	FT_ASSERT(src != NULL || len == 0);
	ret = dst;
	if (dst > src)
		cpy_right(dst + len, src + len, len);
	else
		cpy_left(dst, src, len);
	return (ret);
}
