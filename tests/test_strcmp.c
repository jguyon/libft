/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:43:13 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 14:57:04 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_equal(t_tap *t)
{
	char	s1[] = "hello world";
	char	s2[] = "hello world";

	FT_TAP_IEQ(t, ft_strcmp(s1, s2), 0);
}

static void	test_greater(t_tap *t)
{
	char	s1[] = "hello world";
	char	s2[] = "hello world";

	s1[4] = 127;
	FT_TAP_IEQ(t, ft_strcmp(s1, s2), 127 - 'o');
}

static void	test_lower(t_tap *t)
{
	char	s1[] = "hello world";
	char	s2[] = "hello world";

	s1[4] = 1;
	FT_TAP_IEQ(t, ft_strcmp(s1, s2), 1 - 'o');
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_equal);
	FT_TAP_TEST(t, test_greater);
	FT_TAP_TEST(t, test_lower);
}
