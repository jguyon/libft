/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:34:19 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 21:31:33 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

static int	do_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (!(*s1) || *s1 != *s2)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		++s1;
		++s2;
		--n;
	}
	return (0);
}

#ifndef FT_MEM_OPT

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	FT_ASSERT(s1 != NULL || n == 0);
	FT_ASSERT(s2 != NULL || n == 0);
	return (do_strncmp(s1, s2, n));
}

#else

static int	opt_strncmp(const char *s1, const char *s2, size_t n)
{
	while (FT_MEM_ALIGN(s1))
	{
		if (!n)
			return (0);
		if (!(*s1) || *s1 != *s2)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		++s1;
		++s2;
		--n;
	}
	while (n > FT_MEM_WORDLEN && !FT_MEM_HASZERO(*((t_mem_word *)s1)))
	{
		if (*((t_mem_word *)s1) != *((t_mem_word *)s2))
			break ;
		s1 += FT_MEM_WORDLEN;
		s2 += FT_MEM_WORDLEN;
		n -= FT_MEM_WORDLEN;
	}
	return (do_strncmp(s1, s2, n));
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	FT_ASSERT(s1 != NULL || n == 0);
	FT_ASSERT(s2 != NULL || n == 0);
	if (FT_MEM_ALIGN(s1) == FT_MEM_ALIGN(s2))
		return (opt_strncmp(s1, s2, n));
	return (do_strncmp(s1, s2, n));
}

#endif
