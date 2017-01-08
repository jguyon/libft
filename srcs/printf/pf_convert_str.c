/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:33:49 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 22:08:05 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "ft_unicode.h"
#include "priv/pf_write.h"
#include "priv/pf_convert.h"

static int		convert_str(t_stream *stream, t_pf_info *info, const char *str)
{
	int			count;
	size_t		len;

	if (!str)
		return (ft_fputs(PF_STRING_NULL, stream));
	len = info->prec < 0 ? ft_strlen(str) : ft_strnlen(str, info->prec);
	if (info->flags.left)
		count = ft_fwrite(str, len, stream)
			+ pf_write_pad(stream, info->min_width, len);
	else
		count = pf_write_pad(stream, info->min_width, len)
			+ ft_fwrite(str, len, stream);
	if (ft_ferror(stream))
		return (-1);
	return (count);
}

static size_t	wstrnlen(const wchar_t *wstr, size_t max)
{
	size_t	len;
	size_t	bytes;

	len = 0;
	while (*wstr)
	{
		if ((bytes = ft_wclen(*wstr)) + len > max)
			break ;
		len += bytes;
		++wstr;
	}
	return (len);
}

static int		convert_wstr(t_stream *stream, t_pf_info *info, const wchar_t *wstr)
{
	int			count;
	size_t		len;

	if (!wstr)
		return (ft_fputs(PF_STRING_NULL, stream));
	len = info->prec < 0 ? ft_wstrlen(wstr) : wstrnlen(wstr, info->prec);
	if (info->flags.left)
		count = pf_write_wstr(stream, wstr, len)
			+ pf_write_pad(stream, info->min_width, len);
	else
		count = pf_write_pad(stream, info->min_width, len)
			+ pf_write_wstr(stream, wstr, len);
	if (ft_ferror(stream))
		return (-1);
	return (count);
}

int				pf_convert_str(t_stream *stream, t_pf_info *info, va_list args)
{
	if (info->mod == L)
		return (convert_wstr(stream, info, va_arg(args, const wchar_t *)));
	else
		return (convert_str(stream, info, va_arg(args, const char *)));
}
