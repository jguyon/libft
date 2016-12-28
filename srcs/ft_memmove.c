/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:24:14 by jguyon            #+#    #+#             */
/*   Updated: 2016/12/28 15:16:49 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*cpy_left(void *dst, const void *src, size_t n)
{
	size_t	align;
	size_t	i;

	align = n & 7;
	i = 0;
	while (i < align)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		++i;
	}
	while (i < n)
	{
		*((uint64_t *)((unsigned char *)dst + i))
			= *((uint64_t *)((unsigned char *)src + i));
		i += 8;
	}
	return (dst);
}

static void	*cpy_right(void *dst, const void *src, size_t n)
{
	size_t	align;
	size_t	i;

	align = n - (n & 7);
	i = n;
	while (i > align)
	{
		--i;
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	while (i)
	{
		i -= 8;
		*((uint64_t *)((unsigned char *)dst + i))
			= *((uint64_t *)((unsigned char *)src + i));
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		return (cpy_right(dst, src, len));
	else
		return (cpy_left(dst, src, len));
}
