/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:08:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/09 02:34:22 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"
#include "ft_memory.h"

int		ft_fflush(t_stream *stm)
{
	size_t	len;
	ssize_t	res;

	if (!stm || !(stm->mode) || ft_ferror(stm))
		return (FT_EOF);
	if (!(stm->curr) || !(stm->write) || (len = stm->curr - stm->buff) == 0)
		return (0);
	if (stm->fd < 0)
		res = stm->write(stm->cookie, stm->buff, len);
	else
		res = stm->write(&(stm->fd), stm->buff, len);
	if (res < 0 || (size_t)res != len)
	{
		stm->error = 1;
		return (FT_EOF);
	}
	stm->curr = stm->buff;
	return (0);
}
