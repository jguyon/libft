/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_darr_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:53:56 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/28 16:31:27 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_darrays.h"
#include <stdlib.h>

static void	test_fill(t_tap *t)
{
	t_darray	darr;
	int			src[] = {0, 1, 2, 3, 4};
	size_t		i;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(int), 0), 0);
	FT_TAP_IEQ(t, ft_darr_copy(&darr, src, 0, sizeof(src) / sizeof(int)), 0);
	FT_TAP_OK(t, darr.size >= sizeof(src) / sizeof(int));
	i = 0;
	while (i < darr.size)
	{
		if (i < sizeof(src) / sizeof(int))
			FT_TAP_IEQ(t, ((int *)darr.array)[i], src[i]);
		else
			FT_TAP_IEQ(t, ((int *)darr.array)[i], 0);
		++i;
	}
	free(darr.array);
}

static void	test_append(t_tap *t)
{
	t_darray	darr;
	int			src[] = {0, 1, 2, 3, 4};
	size_t		i;
	int			val = 42;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(int), 0), 0);
	FT_TAP_IEQ(t, ft_darr_set(&darr, 0, &val), 0);
	FT_TAP_IEQ(t, ft_darr_copy(&darr, src, 1, sizeof(src) / sizeof(int)), 0);
	i = 0;
	while (i < darr.size)
	{
		if (i == 0)
			FT_TAP_IEQ(t, ((int *)darr.array)[i], val);
		else if (i - 1 < sizeof(src) / sizeof(int))
			FT_TAP_IEQ(t, ((int *)darr.array)[i], src[i - 1]);
		else
			FT_TAP_IEQ(t, ((int *)darr.array)[i], 0);
		++i;
	}
	free(darr.array);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_fill);
	FT_TAP_TEST(t, test_append);
}
