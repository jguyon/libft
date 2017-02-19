/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:57:55 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/19 20:26:48 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_program.h"
#include "ft_printf.h"
#include "ft_strings.h"
#include "ft_chars.h"

#define OPTERR(p, c) "%s: illegal option -- %c\n", p, c
#define ARGERR(p, c) "%s: option requires an argument -- %c\n", p, c
#define IS_OPT_START(str) (str && str[0] == '-' && str[1] && str[1] != '-')
#define IS_OPT_END(str) (str && str[0] == '-' && str[1] == '-' && str[2])
#define MISSING_OPT '?'
#define ARG_INDICATOR ':'
#define IS_VALID_OPT(c) ft_isalnum(c)

enum		e_opt_err {
	ERR_OPT,
	ERR_ARG,
};

char		*g_ft_optarg = NULL;

int			g_ft_opterr = 1;

int			g_ft_optind = 1;

int			g_ft_optopt = 0;

static char	*next_option(int argc, char *const argv[])
{
	static int	curr_index = 0;
	static char	*curr_char = NULL;

	if (g_ft_optind < 1 || g_ft_optind != curr_index || !curr_char)
	{
		if (g_ft_optind < 1)
			g_ft_optind = 1;
		curr_char = g_ft_optind < argc ? argv[g_ft_optind] : NULL;
		if (!IS_OPT_START(curr_char))
		{
			if (IS_OPT_END(curr_char))
				++g_ft_optind;
			return (NULL);
		}
		curr_index = g_ft_optind;
	}
	++curr_char;
	return (curr_char);
}

static int	missing(enum e_opt_err err, char opt, const char *optstring)
{
	if (optstring[0] == ARG_INDICATOR)
	{
		if (err == ERR_OPT)
			return (MISSING_OPT);
		else if (err == ERR_ARG)
			return (ARG_INDICATOR);
	}
	if (g_ft_opterr)
	{
		ft_fflush(FT_STDOUT);
		if (err == ERR_OPT)
			ft_fprintf(FT_STDERR, OPTERR(ft_getprogname(), opt));
		else if (err == ERR_ARG)
			ft_fprintf(FT_STDERR, ARGERR(ft_getprogname(), opt));
		ft_fflush(FT_STDERR);
	}
	return (MISSING_OPT);
}

int			ft_getopt(int argc, char *const argv[], const char *optstring)
{
	char	*argvopt;
	char	*stropt;

	if (!(argvopt = next_option(argc, argv)))
		return (-1);
	g_ft_optopt = *argvopt;
	if (*(argvopt + 1) == '\0')
		++g_ft_optind;
	if (!IS_VALID_OPT(*argvopt) || !(stropt = ft_strchr(optstring, *argvopt)))
		return (missing(ERR_OPT, *argvopt, optstring));
	if (*(stropt + 1) == ARG_INDICATOR)
	{
		if (*(argvopt + 1) == '\0')
			g_ft_optarg = argv[g_ft_optind];
		else
			g_ft_optarg = argvopt + 1;
		++g_ft_optind;
		if (g_ft_optind > argc)
			return (missing(ERR_ARG, g_ft_optopt, optstring));
	}
	return (g_ft_optopt);
}
