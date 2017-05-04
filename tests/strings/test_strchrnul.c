/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchrnul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:32:00 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 19:35:37 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"
#include <string.h>

static void	test_found(t_tap *t)
{
	char	src[] = "hello world";

	FT_TAP_IEQ(t, ft_strchrnul(src, 'l') - src, 2);
}

static void	test_not_found(t_tap *t)
{
	char	src[] = "hello world";

	FT_TAP_IEQ(t, ft_strchrnul(src, 'a') - src, 11);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_found);
	FT_TAP_TEST(t, test_not_found);
}
