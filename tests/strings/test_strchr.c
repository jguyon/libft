/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:36:29 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 19:40:27 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_found(t_tap *t)
{
	char	src[] = "hello world";
	char	*res_ft;
	char	*res_lc;

	res_ft = ft_strchr(src, 'l');
	res_lc = strchr(src, 'l');
	FT_TAP_IEQ(t, res_ft - src, res_lc - src);
}

static void	test_not_found(t_tap *t)
{
	char	src[] = "hello world";
	char	*res_ft;
	char	*res_lc;

	res_ft = ft_strchr(src, 'a');
	res_lc = strchr(src, 'a');
	FT_TAP_IEQ(t, res_ft - src, res_lc - src);
}

static void	test_nul(t_tap *t)
{
	char	src[] = "hello world";
	char	*res_ft;
	char	*res_lc;

	res_ft = ft_strchr(src, '\0');
	res_lc = strchr(src, '\0');
	FT_TAP_IEQ(t, res_ft - src, res_lc - src);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_found);
	FT_TAP_TEST(t, test_not_found);
	FT_TAP_TEST(t, test_nul);
}
