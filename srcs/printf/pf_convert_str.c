/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:33:49 by jguyon            #+#    #+#             */
/*   Updated: 2017/05/03 19:31:19 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "priv/pf_write.h"
#include "priv/pf_convert.h"

static size_t	convert_str(t_stream *stream, t_pf_info *info, const char *str)
{
	size_t		count;
	size_t		len;

	if (!str)
	{
		return (ft_fwrite(PF_STRING_NULL,
			1, ft_strlen(PF_STRING_NULL), stream));
	}
	len = info->prec < 0 ? ft_strlen(str) : ft_strnlen(str, info->prec);
	if (info->flags.left || info->min_width < 0)
		count = pf_write_str(stream, str, len)
			+ pf_write_pad(stream, ' ', PF_ABS(info->min_width), len);
	else
		count = pf_write_pad(stream, ' ', info->min_width, len)
			+ pf_write_str(stream, str, len);
	return (count);
}

int				pf_convert_str(t_stream *stream, t_pf_info *info, va_list args)
{
	size_t	count;

	count = convert_str(stream, info, va_arg(args, const char *));
	if (ft_ferror(stream))
		return (-1);
	return ((int)count);
}
