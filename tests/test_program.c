/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:02:25 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/19 20:23:53 by jguyon           ###   ########.fr       */
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

static void	test_getopt(t_tap *t)
{
	char	*argv1[] = {"prog", "-a", "-bc", "arg1", "--" "-abc", NULL};

	g_ft_opterr = 0;
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc"), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc"), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc"), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, g_ft_optind, 3);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc"), -1);
	FT_TAP_IEQ(t, g_ft_optind, 3);
	g_ft_optind = 1;
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "ab"), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "ab"), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "ab"), '?');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, g_ft_optind, 3);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "ab"), -1);
	FT_TAP_IEQ(t, g_ft_optind, 3);
	g_ft_optind = 1;
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc:"), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc:"), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc:"), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, g_ft_optind, 4);
	FT_TAP_SEQ(t, g_ft_optarg, "arg1");
	FT_TAP_IEQ(t, ft_getopt(6, argv1, "abc:"), -1);
	FT_TAP_IEQ(t, g_ft_optind, 5);
	g_ft_optind = 1;
	FT_TAP_IEQ(t, ft_getopt(3, argv1, ":abc:"), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(3, argv1, ":abc:"), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(3, argv1, ":abc:"), ':');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, g_ft_optind, 4);
	FT_TAP_IEQ(t, ft_getopt(3, argv1, ":abc:"), -1);
	FT_TAP_IEQ(t, g_ft_optind, 4);
	g_ft_optind = 1;
	FT_TAP_IEQ(t, ft_getopt(3, argv1, "ab:c"), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, g_ft_optind, 2);
	FT_TAP_IEQ(t, ft_getopt(3, argv1, "ab:c"), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, g_ft_optind, 3);
	FT_TAP_SEQ(t, g_ft_optarg, "c");
	FT_TAP_IEQ(t, ft_getopt(3, argv1, "ab:c"), -1);
	FT_TAP_IEQ(t, g_ft_optind, 3);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_cleanup_std);
	FT_TAP_TEST(t, test_cleanup_failure);
	FT_TAP_TEST(t, test_cleanup_success);
	FT_TAP_TEST(t, test_progname);
	FT_TAP_TEST(t, test_getopt);
}
