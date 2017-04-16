/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:00:42 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 20:05:21 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_find_empty(t_tap *t)
{
	char	src[] = "hello world";
	char	*res_ft;
	char	*res_lc;

	res_ft = ft_strstr(src, "");
	res_lc = strstr(src, "");
	FT_TAP_IEQ(t, res_ft - src, res_lc - src);
}

static void	test_find_nonempty(t_tap *t)
{
	char	src[] = "hello world";
	char	*res_ft;
	char	*res_lc;

	res_ft = ft_strstr(src, "lo");
	res_lc = strstr(src, "lo");
	FT_TAP_IEQ(t, res_ft - src, res_lc - src);
}

static void	test_find_nothing(t_tap *t)
{
	char	src[] = "hello world";
	char	*res_ft;
	char	*res_lc;

	res_ft = ft_strstr(src, "la");
	res_lc = strstr(src, "la");
	FT_TAP_IEQ(t, res_ft - src, res_lc - src);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_find_empty);
	FT_TAP_TEST(t, test_find_nonempty);
	FT_TAP_TEST(t, test_find_nothing);
}
