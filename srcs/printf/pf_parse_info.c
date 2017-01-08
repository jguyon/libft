/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:55:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 17:02:38 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "priv/pf_parse.h"

const char	*pf_parse_info(const char *format, t_pf_info *info)
{
	if (!(*format))
		return (NULL);
	info->spec = *(format++);
	return (format);
}
