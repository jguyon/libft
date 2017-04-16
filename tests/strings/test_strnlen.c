/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:29:28 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 18:33:24 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"

static void	test_empty(t_tap *t)
{
	char	str[32] = "";

	FT_TAP_UEQ(t, ft_strnlen(str, sizeof(str)), 0);
}

static void	test_lower(t_tap *t)
{
	char	str[32] = "hello world";

	FT_TAP_UEQ(t, ft_strnlen(str, sizeof(str)), 11);
}

static void	test_greater(t_tap *t)
{
	char	str[32] = "hello world";

	FT_TAP_UEQ(t, ft_strnlen(str, 3), 3);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_lower);
	FT_TAP_TEST(t, test_greater);
}
