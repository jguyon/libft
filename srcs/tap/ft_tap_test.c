/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:30:58 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/02 15:19:34 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

int		ft_tap_test(t_tap *t, void (*test)(t_tap *s), const char *msg)
{
	t_tap	sub;

	if (!msg)
		msg = "passes";
	g_ft_tprintf("%*s# Subtest: %s\n", (int)t->nesting, "", msg);
	sub.nesting = t->nesting + 4;
	sub.plan = 0;
	sub.run = 0;
	sub.passed = 0;
	test(&sub);
	if (sub.plan && sub.plan != sub.run)
		ft_tap_fail(&sub, "respects plan");
	else if (sub.plan)
		ft_tap_pass(&sub, "respects plan");
	g_ft_tprintf("%*s1..%zu\n", (int)sub.nesting, "", sub.run);
	if (sub.passed != sub.run)
		ft_tap_fail(t, msg);
	else
		ft_tap_pass(t, msg);
	return (sub.passed == sub.run);
}
