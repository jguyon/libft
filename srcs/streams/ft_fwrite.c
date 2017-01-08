/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:02:35 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 14:00:15 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_streams.h"

size_t	ft_fwrite(const char *s, size_t count, t_stream *stream)
{
	size_t	i;
	size_t	size;

	if (!stream || !(stream->curr) || !(stream->type.write))
		return (0);
	i = count;
	while (i)
	{
		size = stream->type.buff_size - (stream->curr - stream->buff);
		if (i < size)
			size = i;
		ft_memcpy(stream->curr, s, size);
		stream->curr += size;
		if (i > size && ft_fflush(stream) < 0)
			break ;
		s += size;
		i -= size;
	}
	return (count - i);
}
