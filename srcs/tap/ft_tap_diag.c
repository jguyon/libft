/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_diag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:36:07 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 11:28:42 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

static void	print_key(t_tap *t, const char *key, const char *val, va_list args)
{
	g_ft_tprintf("%*s %s: ", (int)t->nesting, "", key);
	g_ft_tvprintf(val, args);
	g_ft_tprintf("\n");
}

void		ft_tap_diag(t_tap *t, va_list parent, ...)
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
			print_key(t, key, val, parent);
			key = va_arg(parent, const char *);
			val = va_arg(parent, const char *);
		}
		va_start(own, parent);
		while ((key = va_arg(own, const char *))
			&& (val = va_arg(own, const char *)))
			print_key(t, key, val, own);
		va_end(own);
		g_ft_tprintf("%*s ...\n", (int)t->nesting, "");
	}
}
