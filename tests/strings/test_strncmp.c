/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:51:54 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 14:57:57 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_equal(t_tap *t)
{
	char	s1[32] = "hello world";
	char	s2[32] = "hello world";

	FT_TAP_IEQ(t, ft_strncmp(s1, s2, sizeof(s1)), 0);
}

static void	test_greater(t_tap *t)
{
	char	s1[32] = "hello world";
	char	s2[32] = "hello world";

	s1[4] = 127;
	FT_TAP_IEQ(t, ft_strncmp(s1, s2, sizeof(s1)), 127 - 'o');
}

static void	test_lower(t_tap *t)
{
	char	s1[32] = "hello world";
	char	s2[32] = "hello world";

	s1[4] = 1;
	FT_TAP_IEQ(t, ft_strncmp(s1, s2, sizeof(s1)), 1 - 'o');
}

static void	test_maxed(t_tap *t)
{
	char	s1[32] = "hello world";
	char	s2[32] = "hello world";

	s1[4] = 1;
	FT_TAP_IEQ(t, ft_strncmp(s1, s2, 4), 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_equal);
	FT_TAP_TEST(t, test_greater);
	FT_TAP_TEST(t, test_lower);
	FT_TAP_TEST(t, test_maxed);
}
