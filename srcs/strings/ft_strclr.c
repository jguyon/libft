/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:22:59 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 21:36:03 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

static void	do_strclr(char *str)
{
	while (*str)
	{
		*str = 0;
		++str;
	}
}

#ifndef FT_MEM_OPT

void		ft_strclr(char *str)
{
	FT_ASSERT(str != NULL);
	do_strclr(str);
}

#else

void	ft_strclr(char *str)
{
	FT_ASSERT(str != NULL);
	while (FT_MEM_ALIGN(str))
	{
		if (!(*str))
			return ;
		*str = 0;
		++str;
	}
	while (!FT_MEM_HASZERO(*((t_mem_word *)str)))
	{
		*((t_mem_word *)str) = 0;
		str += FT_MEM_WORDLEN;
	}
	do_strclr(str);
}

#endif
