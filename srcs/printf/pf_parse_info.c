/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:55:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 20:02:18 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_memory.h"
#include "ft_chars.h"
#include "priv/pf_parse.h"

static int		read_flag(const char *format, t_pf_flags *flags)
{
	if (*format == PF_FLAG_LEFT)
		flags->left = 1;
	else
		return (0);
	return (1);
}

static size_t	read_modifier(const char *format, t_mod *mod)
{
	if (*format == PF_MOD_L && *(format + 1) == PF_MOD_L)
		*mod = LL;
	else if (*format == PF_MOD_L)
		*mod = L;
	else if (*format == PF_MOD_H && *(format + 1) == PF_MOD_H)
		*mod = HH;
	else if (*format == PF_MOD_H)
		*mod = H;
	else if (*format == PF_MOD_J)
		*mod = J;
	else if (*format == PF_MOD_Z)
		*mod = Z;
	else
		*mod = NO_MOD;
	if (*mod == NO_MOD)
		return (0);
	if (*mod == LL || *mod == HH)
		return (2);
	return (1);
}

const char		*pf_parse_info(const char *format, t_pf_info *info)
{
	if (!(*format))
		return (NULL);
	ft_bzero(info, sizeof(*info));
	while (read_flag(format, &(info->flags)))
		++format;
	while (ft_isdigit(*format))
		info->min_width = 10 * info->min_width + (*(format++) - '0');
	if (*format == PF_PREC_PREFIX)
	{
		while (ft_isdigit(*(++format)))
			info->prec = 10 * info->prec + (*format - '0');
	}
	else
		info->prec = -1;
	format += read_modifier(format, &(info->mod));
	info->spec = *(format++);
	return (format);
}
