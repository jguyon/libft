/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:02:35 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/02 21:18:26 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_streams.h"

size_t	ft_fwrite(const char *s, size_t count, t_stream *stream)
{
	size_t	i;

	if (!stream || !(stream->curr) || !(stream->type.write))
		return (0);
	i = 0;
	while (i < count)
	{
		if ((size_t)(stream->curr - stream->buff) >= stream->type.buff_size)
		{
			if (stream->type.write(stream->cookie, stream->buff,
								   stream->type.buff_size)
				!= stream->type.buff_size)
			{
				stream->curr = NULL;
				break ;
			}
			stream->curr = stream->buff;
		}
		*(stream->curr) = s[i];
		++(stream->curr);
		++i;
	}
	return (i);
}
