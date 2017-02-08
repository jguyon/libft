/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopencookie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:56:27 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/08 22:04:51 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"
#include "ft_memory.h"
#include "ft_strings.h"

t_stream	*ft_fopencookie(void *cookie, const char *mode, t_stream_funs funs)
{
	t_stream	*stream;

	if (ft_strcmp(mode, "w")
		|| !(stream = (t_stream *)ft_memalloc(sizeof(*stream))))
		return (NULL);
	stream->write = funs.write;
	stream->close = funs.close;
	stream->cookie = cookie;
	stream->mode = FT_IOFBF;
	stream->size = FT_BUFSIZ;
	return (stream);
}
