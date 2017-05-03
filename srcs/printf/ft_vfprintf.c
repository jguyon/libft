/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:50:26 by jguyon            #+#    #+#             */
/*   Updated: 2017/05/03 23:24:04 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "priv/pf_parse.h"
#include "ft_strings.h"
#include "ft_debug.h"
#include <limits.h>
#include <stdint.h>

static int	write_literal(t_stream *stm, const char *format, size_t size)
{
	size_t	count;

	count = ft_fwrite(format, 1, size, stm);
	if (count > INT_MAX)
		return (-1);
	return (count);
}

static int	write_conv(t_stream *stm, size_t count,
				const char **format, va_list args)
{
	size_t		conv_count;
	t_pf_info	info;
	int			res;

	conv_count = 0;
	if (**format == PF_CONV_PREFIX)
	{
		conv_count = ft_fwrite(*format, 1, 1, stm);
		++(*format);
	}
	else if ((*format = pf_parse_info(*format, &info, count, args)))
	{
		if ((res = pf_convert(stm, &info, args)) < 0)
			return (-1);
		conv_count = res;
	}
	if (!(*format) || ft_ferror(stm) || conv_count > INT_MAX)
		return (-1);
	return (conv_count);
}

int			ft_vfprintf(t_stream *stream, const char *format, va_list args)
{
	size_t		count;
	int			res;
	char		*next;

	FT_ASSERT(stream != NULL);
	FT_ASSERT(format != NULL);
	if (ft_ferror(stream))
		return (-1);
	count = 0;
	while ((next = ft_strchrnul(format, PF_CONV_PREFIX)))
	{
		if ((res = write_literal(stream, format, next - format)) < 0
			|| (size_t)(INT_MAX - res) < count)
			return (-1);
		count += res;
		if (res != next - format || !(*next))
			break ;
		format = next + 1;
		if ((res = write_conv(stream, count, &format, args)) < 0
			|| (size_t)(INT_MAX - res) < count)
			return (-1);
		count += res;
	}
	return (count);
}
