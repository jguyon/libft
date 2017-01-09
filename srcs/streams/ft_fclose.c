/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:07:40 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/09 17:44:34 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_streams.h"

int		ft_fclose(t_stream *stream)
{
	int		res;

	if (!stream || (stream->buff && !(stream->curr)))
		return (-1);
	ft_fflush(stream);
	res = stream->funs.close ? stream->funs.close(stream->cookie) : 0;
	res = ft_ferror(stream) ? -1 : res;
	if (stream->own)
		free(stream->buff);
	free(stream);
	return (res);
}
