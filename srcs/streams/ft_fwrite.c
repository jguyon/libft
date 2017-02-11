/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:02:35 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/11 02:17:23 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"
#include "ft_memory.h"

static size_t	write_nbf(const void *mem, size_t size, size_t n, t_stream *stm)
{
	ssize_t	res;

	if (!(stm->write))
		return (n);
	if (stm->fd < 0)
		res = stm->write(stm->cookie, mem, size * n);
	else
		res = stm->write(&(stm->fd), mem, size * n);
	if (res < 0 || (size_t)res != size * n)
	{
		stm->error = 1;
		res = res < 0 ? 0 : res;
	}
	return ((size_t)res / size);
}

static size_t	write_fbf(const void *mem, size_t size, size_t n, t_stream *stm)
{
	size_t	bytes;
	size_t	len;

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
	return (n);
}

size_t			ft_fwrite(const void *mem, size_t size, size_t n, t_stream *stm)
{
	if (!stm || !(stm->mode) || size * n == 0 || ft_ferror(stm))
		return (0);
	if (stm->mode == FT_IONBF)
		return (write_nbf(mem, size, n, stm));
	if (!(stm->buff) && !(stm->buff = (char *)ft_memalloc(stm->size)))
	{
		stm->error = 1;
		return (0);
	}
	if (!(stm->curr))
		stm->curr = stm->buff;
	return (write_fbf(mem, size, n, stm));
}
