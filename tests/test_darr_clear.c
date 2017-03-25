/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_darr_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:47:19 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/21 16:52:44 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_darrays.h"
#include <stdlib.h>

static void	test_before_set(t_tap *t)
{
	t_darray	darr;
	int			val = 42;

	FT_TAP_IEQ(t, ft_darr_init(&darr, NULL, sizeof(int), 8), 0);
	FT_TAP_OK(t, darr.array != NULL);
	FT_TAP_OK(t, darr.size >= 8);
	ft_darr_clear(&darr);
	FT_TAP_OK(t, darr.array == NULL);
	FT_TAP_UEQ(t, darr.size, 0);
	FT_TAP_IEQ(t, ft_darr_set(&darr, 3, &val), 0);
	FT_TAP_IEQ(t, ((int *)darr.array)[3], val);
	free(darr.array);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_before_set);
}
