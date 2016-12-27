/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:59:10 by jguyon            #+#    #+#             */
/*   Updated: 2016/12/27 17:05:04 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

TFT_TEST(test_memset)
{
	char	mem_ft[200] = {0};
	char	mem_lc[200] = {0};

	ft_memset(mem_ft, 1, 200);
	memset(mem_lc, 1, 200);
	TFT_ASSERT(memcmp(mem_ft, mem_lc, 200) == 0);
}

void	test_strings(void)
{
	TFT_RUN(test_memset);
}
