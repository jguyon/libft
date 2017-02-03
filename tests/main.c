/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:15:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 21:18:11 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include <string.h>
#include <stdio.h>

int		main(void)
{
	t_tap	t;

	g_ft_tprintf = &printf;
	g_ft_tvprintf = &vprintf;
	g_ft_tstrlen = &strlen;
	g_ft_tstrcmp = &strcmp;
	ft_tap_start(&t);
	FT_TAP_TEST(&t, test_memory);
	FT_TAP_TEST(&t, test_strings);
	FT_TAP_TEST(&t, test_dlists);
	FT_TAP_TEST(&t, test_streams);
	ft_tap_end(&t);
}
