/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_diag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:36:07 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/02 20:28:10 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

void	ft_tap_diag(t_tap *t, va_list parent, ...)
{
	va_list		own;
	const char	*key;
	const char	*val;

	if ((key = va_arg(parent, const char *))
		&& (val = va_arg(parent, const char *)))
	{
		g_ft_tprintf("%*s ---\n", (int)t->nesting, "");
		while (key && val)
		{
			g_ft_tprintf("%*s %s: %s\n", (int)t->nesting, "", key, val);
			key = va_arg(parent, const char *);
			val = va_arg(parent, const char *);
		}
		va_start(own, parent);
		while ((key = va_arg(own, const char *))
			&& (val = va_arg(own, const char *)))
			g_ft_tprintf("%*s %s: %s\n", (int)t->nesting, "", key, val);
		va_end(own);
		g_ft_tprintf("%*s ...\n", (int)t->nesting, "");
	}
}
