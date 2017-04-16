/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:54:36 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 22:08:56 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_debug.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*start;

	FT_ASSERT(dst != NULL);
	FT_ASSERT(src != NULL);
	start = dst;
	dst += ft_strnlen(dst, size);
	while (*src && (size_t)(dst - start) < (size - 1))
	{
		*dst = *src;
		++dst;
		++src;
	}
	if ((size_t)(dst - start) < size)
		*dst = '\0';
	return (ft_strlen(src) + (size_t)(dst - start));
}
