/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_darrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 01:28:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/20 02:35:48 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_darrays.h"
#include <string.h>

static void	test_basic(t_tap *t)
{
	t_darray	arr;
	int			val;
	size_t		i;

	FT_TAP_IEQ(t, ft_darr_init(&arr, NULL, sizeof(val), 32), 0);
	FT_TAP_OK(t, arr.size >= 32);
	i = 0;
	while (i < arr.size * 2)
	{
		val = -1;
		ft_darr_get(&arr, i, &val);
		FT_TAP_IEQ(t, val, 0);
		++i;
	}
	i *= 2;
	FT_TAP_IEQ(t, ft_darr_set(&arr, i, NULL), 0);
	FT_TAP_OK(t, arr.size >= i + 1);
	i = 0;
	while (i < arr.size * 2)
	{
		val = -1;
		ft_darr_get(&arr, i, &val);
		FT_TAP_IEQ(t, val, 0);
		++i;
	}
	ft_darr_clear(&arr);
}

static void	test_default(t_tap *t)
{
	t_darray	arr;
	int			val;
	size_t		i;

	val = -1;
	FT_TAP_IEQ(t, ft_darr_init(&arr, &val, sizeof(val), 32), 0);
	FT_TAP_OK(t, arr.size >= 32);
	i = 0;
	while (i < arr.size * 2)
	{
		val = 0;
		ft_darr_get(&arr, i, &val);
		FT_TAP_IEQ(t, val, -1);
		++i;
	}
	i *= 2;
	FT_TAP_IEQ(t, ft_darr_set(&arr, i, NULL), 0);
	FT_TAP_OK(t, arr.size >= i + 1);
	i = 0;
	while (i < arr.size * 2)
	{
		val = 0;
		ft_darr_get(&arr, i, &val);
		FT_TAP_IEQ(t, val, -1);
		++i;
	}
	ft_darr_clear(&arr);
}

static void	test_copy(t_tap *t)
{
	t_darray	arr;
	int			val;
	size_t		i;
	int			carr[59] = {0};

	val = 1;
	FT_TAP_IEQ(t, ft_darr_init(&arr, &val, sizeof(val), 0), 0);
	FT_TAP_IEQ(t, ft_darr_copy(&arr, carr, 12, sizeof(carr) / sizeof(val)), 0);
	FT_TAP_OK(t, arr.size >= sizeof(carr) / sizeof(val));
	i = 0;
	while (i < arr.size)
	{
		val = -1;
		ft_darr_get(&arr, i, &val);
		if (i < 12 || i >= 12 + sizeof(carr) / sizeof(val))
			FT_TAP_IEQ(t, val, 1);
		else
			FT_TAP_IEQ(t, val, 0);
		++i;
	}
	ft_darr_clear(&arr);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_basic);
	FT_TAP_TEST(t, test_default);
	FT_TAP_TEST(t, test_copy);
}
