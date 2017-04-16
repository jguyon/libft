/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:15:07 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 19:28:22 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_debug.h"

static void	do_bzero(void *str, size_t n)
{
	while (n)
	{
		*((unsigned char *)str) = 0;
		++str;
		--n;
	}
}

#ifndef FT_MEM_OPT

void		ft_bzero(void *str, size_t n)
{
	FT_ASSERT(str != NULL || n == 0);
	do_bzero(str, n);
}

#else

void		ft_bzero(void *str, size_t n)
{
	FT_ASSERT(str != NULL || n == 0);
	while (FT_MEM_ALIGN(str))
	{
		if (!n)
			return ;
		*((unsigned char *)str) = 0;
		++str;
		--n;
	}
	while (n >= FT_MEM_WORDLEN)
	{
		*((t_mem_word *)str) = 0;
		str += FT_MEM_WORDLEN;
		n -= FT_MEM_WORDLEN;
	}
	do_bzero(str, n);
}

#endif
