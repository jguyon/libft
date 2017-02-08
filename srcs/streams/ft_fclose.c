/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:07:40 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/08 19:10:43 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"
#include "ft_memory.h"

int		ft_fclose(t_stream *stm)
{
	int		res;

	res = 0;
	if (ft_fflush(stm) == FT_EOF)
		res = FT_EOF;
	if (!(stm->user_buff))
		ft_memdel((void **)&(stm->buff));
	if (stm->close && stm->close(stm->cookie) == FT_EOF)
		res = FT_EOF;
	ft_memdel((void **)&(stm));
	return (res);
}
