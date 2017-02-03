/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_seq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:48:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 14:02:24 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

int		ft_tap_seq(t_tap *t, const char *a, const char *b, const char *msg, ...)
{
	va_list	args;
	int		res;

	if (!msg)
		msg = "are equal";
	if ((res = g_ft_strcmp(a, b) == 0))
		ft_tap_pass(t, msg);
	else
	{
		ft_tap_fail(t, msg);
		a = ft_tap_quote(a);
		b = ft_tap_quote(b);
		va_start(args, msg);
		ft_tap_diag(t, args, "wanted", "%s", b, "found", "%s", a, NULL);
		va_end(args);
	}
	return (res);
}
