/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_darr_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:39:21 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/21 16:46:31 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_darrays.h"
#include <stdlib.h>

static void	test_in_bounds(t_tap *t)
{
	t_darray	darr;
	int			val = 42;
	int			actual = 0;

	FT_TAP_IEQ(t, ft_darr_init(&darr, NULL, sizeof(int), 0), 0);
	FT_TAP_IEQ(t, ft_darr_set(&darr, 3, &val), 0);
	ft_darr_get(&darr, 3, &actual);
	FT_TAP_IEQ(t, actual, val);
	free(darr.array);
}

static void	test_out_bounds(t_tap *t)
{
	t_darray	darr;
	int			actual = 0;
	int			dflt = -1;

	FT_TAP_IEQ(t, ft_darr_init(&darr, &dflt, sizeof(int), 0), 0);
	ft_darr_get(&darr, darr.size, &actual);
	FT_TAP_IEQ(t, actual, dflt);
	free(darr.array);
}


void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_in_bounds);
	FT_TAP_TEST(t, test_out_bounds);
}
