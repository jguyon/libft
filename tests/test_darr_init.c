/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_darr_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:51:29 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/21 16:53:43 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_darrays.h"
#include <stdlib.h>

static void	test_no_default(t_tap *t)
{
	t_darray	darr;
	size_t		i;

	FT_TAP_IEQ(t, ft_darr_init(&darr, NULL, sizeof(int), 8), 0);
	FT_TAP_OK(t, darr.size >= 8);
	FT_TAP_UEQ(t, darr.item_size, sizeof(int));
	i = 0;
	while (i < darr.size)
	{
		FT_TAP_UEQ(t, ((int *)darr.array)[i], 0),
		++i;
	}
	free(darr.array);
}

static void	test_with_default(t_tap *t)
{
	t_darray	darr;
	size_t		i;
	int			dflt = -1;

	FT_TAP_IEQ(t, ft_darr_init(&darr, &dflt, sizeof(int), 8), 0);
	FT_TAP_OK(t, darr.size >= 8);
	FT_TAP_UEQ(t, darr.item_size, sizeof(int));
	i = 0;
	while (i < darr.size)
	{
		FT_TAP_IEQ(t, ((int *)darr.array)[i], dflt);
		++i;
	}
	free(darr.array);
}

static void	test_empty(t_tap *t)
{
	t_darray	darr;

	FT_TAP_IEQ(t, ft_darr_init(&darr, NULL, sizeof(int), 0), 0);
	FT_TAP_UEQ(t, darr.size, 0);
	FT_TAP_OK(t, darr.array == NULL);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_no_default);
	FT_TAP_TEST(t, test_with_default);
	FT_TAP_TEST(t, test_empty);
}
