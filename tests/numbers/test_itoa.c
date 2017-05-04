/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:20:20 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/22 14:32:18 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_numbers.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

static void	test_numbers(t_tap *t)
{
	char	*str;

	FT_TAP_SEQ(t, (str = ft_itoa(821)), "821");
	free(str);
	FT_TAP_SEQ(t, (str = ft_itoa(0)), "0");
	free(str);
	FT_TAP_SEQ(t, (str = ft_itoa(-821)), "-821");
	free(str);
}

static void	test_limits(t_tap *t)
{
	char	num[256];
	char	*str;

	snprintf(num, sizeof(num), "%d", INT_MAX);
	FT_TAP_SEQ(t, (str = ft_itoa(INT_MAX)), num);
	free(str);
	snprintf(num, sizeof(num), "%d", INT_MIN);
	FT_TAP_SEQ(t, (str = ft_itoa(INT_MIN)), num);
	free(str);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_numbers);
	FT_TAP_TEST(t, test_limits);
}
