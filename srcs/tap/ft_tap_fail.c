/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:22:21 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/02 19:44:40 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

void	ft_tap_fail(t_tap *t, const char *msg)
{
	t->run += 1;
	if (msg)
		g_ft_tprintf("%*snot ok %zu - %s\n", (int)t->nesting, "", t->run, msg);
	else
		g_ft_tprintf("%*snot ok %zu\n", (int)t->nesting, "", t->run);
}
