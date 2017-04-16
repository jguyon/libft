/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:50:47 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 19:07:33 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_debug.h"

static void	*do_memccpy(void *dst, const void *src, unsigned char c, size_t n)
{
	while (n)
	{
		if ((*((unsigned char *)dst) = *((unsigned char *)src)) == c)
			return (dst + 1);
		++dst;
		++src;
		--n;
	}
	return (NULL);
}

#ifndef FT_MEM_OPT

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	FT_ASSERT(dst != NULL || n == 0);
	FT_ASSERT(src != NULL || n == 0);
	return (do_memccpy(dst, src, (unsigned char)c, n));
}

#else

static void	*opt_memccpy(void *dst, const void *src, unsigned char c, size_t n)
{
	t_mem_word	word;

	while (FT_MEM_ALIGN(dst))
	{
		if (!n)
			return (NULL);
		if ((*((unsigned char *)dst) = *((unsigned char *)src)) == c)
			return (dst + 1);
		++dst;
		++src;
		--n;
	}
	word = FT_MEM_WORD(c);
	while (n > FT_MEM_WORDLEN
		&& !FT_MEM_HASZERO(*((t_mem_word *)src) ^ word))
	{
		*((t_mem_word *)dst) = *((t_mem_word *)src);
		dst += FT_MEM_WORDLEN;
		src += FT_MEM_WORDLEN;
		n -= FT_MEM_WORDLEN;
	}
	return (do_memccpy(dst, src, c, n));
}

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	FT_ASSERT(dst != NULL || n == 0);
	FT_ASSERT(src != NULL || n == 0);
	if (FT_MEM_ALIGN(src) == FT_MEM_ALIGN(dst))
		return (opt_memccpy(dst, src, (unsigned char)c, n));
	return (do_memccpy(dst, src, (unsigned char)c, n));
}

#endif
