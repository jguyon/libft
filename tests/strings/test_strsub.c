/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:19:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 20:22:38 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	test_sub(t_tap *t)
{
	char	str[] = "hello world";
	char	*res;

	res = ft_strsub(str, 3, 5);
	FT_TAP_SEQ(t, res, "lo wo");
	free(res);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_sub);
}
