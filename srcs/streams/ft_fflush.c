/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:08:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/02 03:25:11 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_streams.h"

int		ft_fflush(t_stream *stream)
{
	if (!stream || !(stream->type.write) || !(stream->curr))
		return (-1);
	if (stream->curr == stream->buff)
		return (0);
	if (stream->type.write(stream->cookie, stream->buff,
							stream->curr - stream->buff))
	{
		stream->curr = stream->buff;
		return (1);
	}
	stream->curr = NULL;
	return (-1);
}