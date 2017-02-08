/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:02:35 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/08 22:19:57 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"
#include "ft_memory.h"

static int	alloc_buff(t_stream *stm)
{
	if (stm->buff)
		return (0);
	if ((stm->buff = (char *)malloc(stm->size)))
	{
		stm->curr = stm->buff;
		return (0);
	}
	stm->error = 1;
	return (-1);
}

size_t		ft_fwrite(const void *mem, size_t size, size_t n, t_stream *stm)
{
	size_t	bytes;
	size_t	len;

	if (!stm || size == 0 || ft_ferror(stm) || alloc_buff(stm))
		return (0);
	bytes = n * size;
	while (bytes)
	{
		len = stm->size - (stm->curr - stm->buff);
		if (bytes < len)
			len = bytes;
		ft_memcpy(stm->curr, mem, len);
		stm->curr += len;
		if (bytes > len && ft_fflush(stm) == FT_EOF)
			return (0);
		mem += len;
		bytes -= len;
	}
	if (stm->mode == FT_IONBF && ft_fflush(stm) == FT_EOF)
		return (0);
	return (n);
}
