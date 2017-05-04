/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:41:49 by jguyon            #+#    #+#             */
/*   Updated: 2017/05/03 19:26:37 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priv/pf_write.h"
#include "priv/pf_convert.h"

static size_t	write_char(t_stream *stream, t_pf_info *info, char c)
{
	size_t	count;

	if (info->flags.left || info->min_width < 0)
		count = pf_write_str(stream, &c, 1)
			+ pf_write_pad(stream, ' ', PF_ABS(info->min_width), 1);
	else
		count = pf_write_pad(stream, ' ', info->min_width, 1)
			+ pf_write_str(stream, &c, 1);
	return (count);
}

int				pf_convert_char(t_stream *stream, t_pf_info *info,
									va_list args)
{
	size_t	count;

	count = write_char(stream, info, (char)va_arg(args, int));
	if (ft_ferror(stream))
		return (-1);
	return ((int)count);
}
