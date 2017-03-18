/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prog_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:34:57 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/18 23:41:11 by jguyon           ###   ########.fr       */
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

static void	test_streams(t_tap *t)
{
	t_stream	*in;
	t_stream	*out;
	t_stream	*err;

	in = FT_STDIN;
	out = FT_STDOUT;
	err = FT_STDERR;
	FT_STDIN = ft_fmemopen(NULL, 16, "r");
	FT_STDOUT = ft_fmemopen(NULL, 16, "w");
	FT_STDERR = ft_fmemopen(NULL, 16, "w");
	ft_cleanup(FT_EXIT_SUCCESS);
	FT_TAP_OK(t, ft_ferror(FT_STDIN));
	FT_TAP_OK(t, ft_ferror(FT_STDOUT));
	FT_TAP_OK(t, ft_ferror(FT_STDERR));
	FT_STDIN = in;
	FT_STDOUT = out;
	FT_STDERR = err;
}

static void	test_success(t_tap *t)
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

static void	test_failure(t_tap *t)
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

void		run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_streams);
	FT_TAP_TEST(t, test_success);
	FT_TAP_TEST(t, test_failure);
}
