/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:06:31 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 20:13:03 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_find_empty(t_tap *t)
{
	char	src[] = "hello world";
	char	*res;

	res = ft_strnstr(src, "", sizeof(src));
	FT_TAP_IEQ(t, res - src, 0);
}

static void	test_find_lower(t_tap *t)
{
	char	src[] = "hello world";
	char	*res;

	res = ft_strnstr(src, "llo", sizeof(src));
	FT_TAP_IEQ(t, res - src, 2);
}

static void	test_find_greater(t_tap *t)
{
	char	src[] = "hello world";
	char	*res;

	res = ft_strnstr(src, "llo ", 5);
	FT_TAP_OK(t, res == NULL);
}

static void	test_find_nothing(t_tap *t)
{
	char	src[] = "hello world";
	char	*res;

	res = ft_strnstr(src, "lla", sizeof(src));
	FT_TAP_OK(t, res == NULL);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_find_empty);
	FT_TAP_TEST(t, test_find_lower);
	FT_TAP_TEST(t, test_find_greater);
	FT_TAP_TEST(t, test_find_nothing);
}
