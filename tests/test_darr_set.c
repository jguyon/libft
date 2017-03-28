/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_darr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:20:18 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/28 16:34:17 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_darrays.h"
#include <stdlib.h>

static void	test_no_growing(t_tap *t)
{
	t_darray	darr;
	int			val = 42;
	size_t		size;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(int), 8), 0);
	size = darr.size;
	FT_TAP_IEQ(t, ft_darr_set(&darr, 7, &val), 0);
	FT_TAP_UEQ(t, darr.size, size);
	FT_TAP_IEQ(t, ((int *)darr.array)[7], val);
	free(darr.array);
}

static void	test_with_growing(t_tap *t)
{
	t_darray	darr;
	int			val = 42;
	size_t		size;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(int), 8), 0);
	size = darr.size;
	FT_TAP_IEQ(t, ft_darr_set(&darr, size, &val), 0);
	FT_TAP_OK(t, darr.size > size);
	FT_TAP_IEQ(t, ((int *)darr.array)[size], val);
	free(darr.array);
}

static void	test_empty(t_tap *t)
{
	t_darray	darr;
	int			val = 42;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(int), 0), 0);
	FT_TAP_IEQ(t, ft_darr_set(&darr, 7, &val), 0);
	FT_TAP_OK(t, darr.size > 7);
	FT_TAP_IEQ(t, ((int *)darr.array)[7], val);
	free(darr.array);
}

static void	test_default(t_tap *t)
{
	t_darray	darr;
	int			val = 42;

	FT_TAP_IEQ(t, ft_darr_init(&darr, sizeof(int), 0), 0);
	FT_TAP_IEQ(t, ft_darr_set(&darr, 7, &val), 0);
	FT_TAP_OK(t, darr.size > 7);
	FT_TAP_IEQ(t, ((int *)darr.array)[7], val);
	FT_TAP_IEQ(t, ft_darr_set(&darr, 7, NULL), 0);
	FT_TAP_IEQ(t, ((int *)darr.array)[7], 0);
	free(darr.array);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_no_growing);
	FT_TAP_TEST(t, test_with_growing);
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_default);
}
