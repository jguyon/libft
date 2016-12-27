/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:57:32 by jguyon            #+#    #+#             */
/*   Updated: 2016/12/27 20:48:25 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			align;
	size_t			i;
	uint64_t		word;

	align = len & 7;
	i = 0;
	while (i < align)
	{
		((unsigned char *)str)[i] = c;
		++i;
	}
	if (i == len)
		return (str);
	word = 0x0101010101010101 * (unsigned char)c;
	while (i < len)
	{
		*((uint64_t *)((unsigned char *)str + i)) = word;
		i += 8;
	}
	return (str);
}
