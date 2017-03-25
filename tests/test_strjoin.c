/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:15:03 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 20:19:29 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	test_join(t_tap *t)
{
	char	*res;

	res = ft_strjoin("hello", " world");
	FT_TAP_SEQ(t, res, "hello world");
	free(res);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_join);
}
