/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:48:19 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/29 14:47:00 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "ft_strings.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_debug(const char *file, int line, const char *fmt, ...)
{
	va_list	args;
	char	msg[LINE_MAX];
	char	debug[LINE_MAX];
	int		count;

	ft_fflush(NULL);
	va_start(args, fmt);
	if (ft_vsnprintf(msg, sizeof(msg), fmt, args) < 0
		|| (count = ft_snprintf(debug, sizeof(debug),
						FT_DEBUG_FMT(file, line, msg))) < 0)
	{
		ft_strcpy(debug, "ft_debug failed\n");
		count = ft_strlen(debug);
	}
	write(FT_DEBUG_FD, debug, count);
	va_end(args);
}
