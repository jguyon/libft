/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvbuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:55:28 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/12 19:08:19 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"

int		ft_setvbuf(t_stream *stm, char *buff, int mode, size_t size)
{
	if (!stm || !(stm->mode) || stm->curr
		|| (mode != FT_IONBF && mode != FT_IOFBF)
		|| (mode != FT_IONBF && size == 0))
		return (FT_EOF);
	if ((stm->mode = mode) == FT_IONBF)
	{
		stm->allocated = 0;
		stm->buff = NULL;
		stm->size = 0;
	}
	else
	{
		stm->allocated = (buff == NULL);
		stm->buff = buff;
		stm->size = size;
	}
	return (0);
}
