/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:00:00 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 19:21:20 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_from_empty(t_tap *t)
{
	char	str_ft[32];
	char	str_lc[sizeof(str_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[] = "";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_ft));
	strcpy(str_ft, "hello world");
	strcpy(str_lc, "hello world");
	res_ft = ft_strncat(str_ft, src, sizeof(str_ft) - strlen(str_ft));
	res_lc = strncat(str_lc, src, sizeof(str_ft) - strlen(str_ft));
	FT_TAP_IEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, memcmp(str_ft, str_lc, sizeof(str_ft)) == 0);
}

static void	test_to_empty(t_tap *t)
{
	char	str_ft[32];
	char	str_lc[sizeof(str_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[] = "hello world";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_ft));
	strcpy(str_ft, "");
	strcpy(str_lc, "");
	res_ft = ft_strncat(str_ft, src, sizeof(str_ft) - strlen(str_ft));
	res_lc = strncat(str_lc, src, sizeof(str_ft) - strlen(str_ft));
	FT_TAP_IEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, memcmp(str_ft, str_lc, sizeof(str_ft)) == 0);
}

static void	test_lower(t_tap *t)
{
	char	str_ft[32];
	char	str_lc[sizeof(str_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[] = "hello world";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_ft));
	strcpy(str_ft, "hello world");
	strcpy(str_lc, "hello world");
	res_ft = ft_strncat(str_ft, src, sizeof(str_ft) - strlen(str_ft));
	res_lc = strncat(str_lc, src, sizeof(str_ft) - strlen(str_lc));
	FT_TAP_IEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, memcmp(str_ft, str_lc, sizeof(str_ft)) == 0);
	FT_TAP_SEQ(t, str_ft, str_lc);
}

static void	test_greater(t_tap *t)
{
	char	str_ft[32];
	char	str_lc[sizeof(str_ft)];
	char	*res_ft;
	char	*res_lc;
	char	src[] = "hello world";

	memset(str_ft, 'a', sizeof(str_ft));
	memset(str_lc, 'a', sizeof(str_ft));
	strcpy(str_ft, "hello world");
	strcpy(str_lc, "hello world");
	res_ft = ft_strncat(str_ft, src, 5);
	res_lc = strncat(str_lc, src, 5);
	FT_TAP_IEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, memcmp(str_ft, str_lc, sizeof(str_ft)) == 0);
	FT_TAP_SEQ(t, str_ft, str_lc);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_from_empty);
	FT_TAP_TEST(t, test_to_empty);
	FT_TAP_TEST(t, test_lower);
	FT_TAP_TEST(t, test_greater);
}
