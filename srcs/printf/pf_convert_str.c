/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:33:49 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 18:44:14 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "priv/pf_write.h"
#include "priv/pf_convert.h"

int		pf_convert_str(t_stream *stream, t_pf_info *info, va_list args)
{
	int			count;
	const char	*str;
	size_t		len;

	str = va_arg(args, const char *);
	if (!str)
		return (ft_fputs(PF_STRING_NULL, stream));
	len = ft_strlen(str);
	count = pf_write_pad(stream, info->min_width, len)
		+ ft_fwrite(str, len, stream);
	if (ft_ferror(stream))
		return (-1);
	return (count);
}
