/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:52:44 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 18:58:35 by jguyon           ###   ########.fr       */
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

	bzero(str_ft, sizeof(str_ft));
	bzero(str_lc, sizeof(str_ft));
	strcpy(str_ft, "hello world");
	strcpy(str_lc, "hello world");
	res_ft = ft_strcat(str_ft, src);
	res_lc = strcat(str_lc, src);
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

	bzero(str_ft, sizeof(str_ft));
	bzero(str_lc, sizeof(str_ft));
	strcpy(str_ft, "");
	strcpy(str_lc, "");
	res_ft = ft_strcat(str_ft, src);
	res_lc = strcat(str_lc, src);
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

	bzero(str_ft, sizeof(str_ft));
	bzero(str_lc, sizeof(str_ft));
	strcpy(str_ft, "goodbye");
	strcpy(str_lc, "goodbye");
	res_ft = ft_strcat(str_ft, src);
	res_lc = strcat(str_lc, src);
	FT_TAP_IEQ(t, res_ft - str_ft, res_lc - str_lc);
	FT_TAP_OK(t, memcmp(str_ft, str_lc, sizeof(str_ft)) == 0);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_from_empty);
	FT_TAP_TEST(t, test_to_empty);
	FT_TAP_TEST(t, test_not_empty);
}
