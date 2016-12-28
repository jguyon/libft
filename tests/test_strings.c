/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:59:10 by jguyon            #+#    #+#             */
/*   Updated: 2016/12/28 10:58:50 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

TFT_TEST(test_memset)
{
	char	mem_ft[200] = {0};
	char	mem_lc[200] = {0};

	TFT_ASSERT(memcmp(ft_memset(mem_ft, 1, 200), memset(mem_lc, 1, 200), 200) == 0);
	TFT_ASSERT(memcmp(ft_memset(mem_ft + 3, 2, 197), memset(mem_lc + 3, 2, 197), 197) == 0);
}

TFT_TEST(test_memcpy)
{
	char	mem_ft[200] = {0};
	char	mem_lc[200] = {0};
	char	src[200] = {0};

	memset(src, 1, 100);
	memset(src + 100, 2, 100);
	TFT_ASSERT(memcmp(ft_memcpy(mem_ft, src, 200), memcpy(mem_lc, src, 200), 200) == 0);
	TFT_ASSERT(memcmp(ft_memcpy(mem_ft + 3, src, 197), memcpy(mem_lc + 3, src, 197), 197) == 0);
}

TFT_TEST(test_strlen)
{
	char	str[256] = {0};

	strcpy(str, "hello");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
	strcpy(str, "hello world hello world hello world hello world");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
	strcpy(str, "");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
	strcpy(str, "hello world");
	TFT_ASSERT(ft_strlen(str) == strlen(str));
}

void	test_strings(void)
{
	TFT_RUN(test_memset);
	TFT_RUN(test_memcpy);
	TFT_RUN(test_strlen);
}
