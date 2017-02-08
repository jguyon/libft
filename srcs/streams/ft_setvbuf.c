/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvbuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:55:28 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/08 18:48:32 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"

int		ft_setvbuf(t_stream *stm, char *buff, int mode, size_t size)
{
	if (!stm || stm->buff || (mode != FT_IONBF && mode != FT_IOFBF))
		return (-1);
	if (mode == FT_IONBF)
	{
		buff = NULL;
		size = FT_BUFSIZ;
	}
	else if (size == 0)
		return (-1);
	stm->mode = mode;
	stm->size = size;
	stm->buff = buff;
	stm->curr = stm->buff;
	stm->user_buff = stm->buff != NULL;
	return (0);
}
