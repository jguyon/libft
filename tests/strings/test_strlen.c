/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:24:13 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 18:28:24 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_strings.h"

static void	test_empty(t_tap *t)
{
	FT_TAP_UEQ(t, ft_strlen(""), 0);
}

static void	test_not_empty(t_tap *t)
{
	FT_TAP_UEQ(t, ft_strlen("hello world"), 11);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_empty);
	FT_TAP_TEST(t, test_not_empty);
}
