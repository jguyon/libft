/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getopt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:59:27 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 23:27:37 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_program.h"

static void	test_separate_opts(t_tap *t)
{
	char	*argv[] = {"prog", "-a", "-b", "-c", "arg", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = "abc";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 4);
}

static void	test_merged_opts(t_tap *t)
{
	char	*argv[] = {"prog", "-abc", "arg", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = "abc";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 2);
}

static void	test_missing_opt(t_tap *t)
{
	char	*argv[] = {"prog", "-abc", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = "ac";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), '?');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 2);
}

static void	test_separate_optarg(t_tap *t)
{
	char	*argv[] = {"prog", "-ab", "barg", "-c", "arg", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = "ab:c";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_SEQ(t, g_ft_optarg, "barg");
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 4);
}

static void	test_merged_optarg(t_tap *t)
{
	char	*argv[] = {"prog", "-abbarg", "-c", "arg", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = "ab:c";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_SEQ(t, g_ft_optarg, "barg");
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 3);
}

static void	test_missing_optarg(t_tap *t)
{
	char	*argv[] = {"prog", "-acb", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = ":ab:c";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), ':');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 2);
}

static void	test_end_opts(t_tap *t)
{
	char	*argv[] = {"prog", "-ab", "--", "-c", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = "abc";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'b');
	FT_TAP_IEQ(t, g_ft_optopt, 'b');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 3);
}

static void	test_end_optarg(t_tap *t)
{
	char	*argv[] = {"prog", "-a", "-cb", "barg", "--", "-c", NULL};
	int		argc = sizeof(argv) / sizeof(argv[0]) - 1;
	char	opts[] = "ab:c";

	g_ft_opterr = 0;
	g_ft_optind = 0;
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'a');
	FT_TAP_IEQ(t, g_ft_optopt, 'a');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'c');
	FT_TAP_IEQ(t, g_ft_optopt, 'c');
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), 'b');
	FT_TAP_SEQ(t, g_ft_optarg, "barg");
	FT_TAP_IEQ(t, ft_getopt(argc, argv, opts), -1);
	FT_TAP_IEQ(t, g_ft_optind, 5);
}

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_separate_opts);
	FT_TAP_TEST(t, test_merged_opts);
	FT_TAP_TEST(t, test_missing_opt);
	FT_TAP_TEST(t, test_separate_optarg);
	FT_TAP_TEST(t, test_merged_optarg);
	FT_TAP_TEST(t, test_missing_optarg);
	FT_TAP_TEST(t, test_end_opts);
	FT_TAP_TEST(t, test_end_optarg);
}
