/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:39:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 18:51:11 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_empty(t_tap *t)
{
	char	str_ft[32];
	char	str_lc[sizeof(str_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[] = "";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_ft));
	res_ft = ft_strcpy(str_ft, src);
	res_lc = strcpy(str_lc, src);
	FT_TAP_IEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, memcmp(str_ft, str_lc, sizeof(str_ft)) == 0);
}

static void	test_not_empty(t_tap *t)
{
	char	str_ft[32];
	char	str_lc[sizeof(str_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[] = "hello world";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_ft));
	res_ft = ft_strcpy(str_ft, src);
	res_lc = strcpy(str_lc, src);
	FT_TAP_IEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, memcmp(str_ft, str_lc, sizeof(str_ft)) == 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_not_empty);
}
