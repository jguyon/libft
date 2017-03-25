/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:43:04 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 19:22:06 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_strings.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	char	*ret;
	size_t	dlen;

	ret = dst;
	dlen = ft_strlen(dst);
	dst += dlen;
	if (!ft_memccpy(dst, src, '\0', len))
		dst[len] = '\0';
	return (ret);
}
