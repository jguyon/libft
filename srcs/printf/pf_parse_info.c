/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:55:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 18:59:49 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_memory.h"
#include "ft_chars.h"
#include "priv/pf_parse.h"

const char	*pf_parse_info(const char *format, t_pf_info *info)
{
	if (!(*format))
		return (NULL);
	ft_bzero(info, sizeof(*info));
	while (ft_isdigit(*format))
		info->min_width = 10 * info->min_width + (*(format++) - '0');
	if (*format == PF_PREC_PREFIX)
	{
		while (ft_isdigit(*(++format)))
			info->prec = 10 * info->prec + (*format - '0');
	}
	else
		info->prec = -1;
	info->spec = *(format++);
	return (format);
}
