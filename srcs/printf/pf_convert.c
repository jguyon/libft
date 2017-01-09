/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:04:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/09 11:22:24 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "priv/pf_convert.h"
#include "priv/pf_parse.h"

static t_conv	*g_convs[CHAR_MAX + 1] = {
	[PF_STRING_SPEC] = &pf_convert_str,
	[PF_INT_SPEC] = &pf_convert_int
};

int				pf_convert(t_stream *stream, t_pf_info *info, va_list args)
{
	if (g_convs[(size_t)info->spec])
		return (g_convs[(size_t)info->spec](stream, info, args));
	return (-1);
}
