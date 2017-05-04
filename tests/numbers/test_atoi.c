/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 13:58:24 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/22 14:18:18 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_numbers.h"
#include <limits.h>
#include <stdio.h>

static void	test_unsigned(t_tap *t)
{
	FT_TAP_IEQ(t, ft_atoi("8"), 8);
	FT_TAP_IEQ(t, ft_atoi("821"), 821);
	FT_TAP_IEQ(t, ft_atoi("0"), 0);
}

static void	test_signed(t_tap *t)
{
	FT_TAP_IEQ(t, ft_atoi("-821"), -821);
	FT_TAP_IEQ(t, ft_atoi("+821"), 821);
	FT_TAP_IEQ(t, ft_atoi("-0"), 0);
	FT_TAP_IEQ(t, ft_atoi("+0"), 0);
}

static void	test_non_digits(t_tap *t)
{
	FT_TAP_IEQ(t, ft_atoi(" \t821"), 821);
	FT_TAP_IEQ(t, ft_atoi("821asdf"), 821);
	FT_TAP_IEQ(t, ft_atoi(" \tasdf"), 0);
}

static void	test_limits(t_tap *t)
{
	char	str[256];

	snprintf(str, sizeof(str), "%d", INT_MAX);
	FT_TAP_IEQ(t, ft_atoi(str), INT_MAX);
	snprintf(str, sizeof(str), "%d", INT_MIN);
	FT_TAP_IEQ(t, ft_atoi(str), INT_MIN);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_unsigned);
	FT_TAP_TEST(t, test_signed);
	FT_TAP_TEST(t, test_non_digits);
	FT_TAP_TEST(t, test_limits);
}
