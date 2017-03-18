/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prog_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:42:48 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 23:46:10 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_program.h"

static void	test_no_slash(t_tap *t)
{
	ft_setprogname("hello");
	FT_TAP_SEQ(t, ft_getprogname(), "hello");
}

static void	test_with_slash(t_tap *t)
{
	ft_setprogname("/hello/world");
	FT_TAP_SEQ(t, ft_getprogname(), "world");
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_no_slash);
	FT_TAP_TEST(t, test_with_slash);
}
