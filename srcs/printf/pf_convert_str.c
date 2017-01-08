/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:33:49 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 17:55:00 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priv/pf_convert.h"

int		pf_convert_str(t_stream *stream, t_pf_info *info, va_list args)
{
	const char	*str;

	(void)info;
	str = va_arg(args, const char *);
	if (!str)
		return (ft_fputs(PF_STRING_NULL, stream));
	return (ft_fputs(str, stream));
}
