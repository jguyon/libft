/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_pass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:16:00 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/02 00:46:33 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

void	ft_tap_pass(t_tap *t, const char *msg)
{
	t->run += 1;
	t->passed += 1;
	if (msg)
		g_ft_tprintf("%*sok %zu - %s\n", (int)t->nesting, "", t->run, msg);
	else
		g_ft_tprintf("%*sok %zu\n", (int)t->nesting, "", t->run);
}
