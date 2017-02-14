/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:02:25 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/14 12:46:48 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_program.h"
#include "ft_streams.h"

static void	cleanup_failure(int status, void *t)
{
	FT_TAP_IEQ(t, status, FT_EXIT_FAILURE);
}

static void	cleanup_success(int status, void *t)
{
	FT_TAP_IEQ(t, status, FT_EXIT_SUCCESS);
}

static void	test_cleanup_std(t_tap *t)
{
	t_stream	in;
	t_stream	out;
	t_stream	err;

	in = *FT_STDIN;
	out = *FT_STDOUT;
	err = *FT_STDERR;
	ft_cleanup(FT_EXIT_SUCCESS);
	FT_TAP_OK(t, ft_ferror(FT_STDIN));
	FT_TAP_OK(t, ft_ferror(FT_STDOUT));
	FT_TAP_OK(t, ft_ferror(FT_STDERR));
	*FT_STDIN = in;
	*FT_STDOUT = out;
	*FT_STDERR = err;
}

static void	test_cleanup_failure(t_tap *t)
{
	size_t		i;

	i = 0;
	while (i < FT_ONEXIT_MAX)
	{
		FT_TAP_NOTOK(t, ft_onexit(&cleanup_failure, t));
		++i;
	}
	FT_TAP_OK(t, ft_onexit(&cleanup_failure, t));
	ft_cleanup(FT_EXIT_FAILURE);
}

static void	test_cleanup_success(t_tap *t)
{
	size_t	i;

	i = 0;
	while (i < FT_ONEXIT_MAX)
	{
		FT_TAP_NOTOK(t, ft_onexit(&cleanup_success, t));
		++i;
	}
	FT_TAP_OK(t, ft_onexit(&cleanup_success, t));
	ft_cleanup(FT_EXIT_SUCCESS);
}

static void	test_progname(t_tap *t)
{
	FT_TAP_SEQ(t, ft_getprogname(), "");
	ft_setprogname("hello");
	FT_TAP_SEQ(t, ft_getprogname(), "hello");
	ft_setprogname("/hello/world");
	FT_TAP_SEQ(t, ft_getprogname(), "world");
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_cleanup_std);
	FT_TAP_TEST(t, test_cleanup_failure);
	FT_TAP_TEST(t, test_cleanup_success);
	FT_TAP_TEST(t, test_progname);
}
