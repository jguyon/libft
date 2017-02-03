/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:05:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 11:29:41 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"
#include "ft_printf.h"

int		(*g_ft_tprintf)(const char *, ...) = &ft_printf;
int		(*g_ft_tvprintf)(const char *, va_list) = &ft_vprintf;

void	ft_tap_start(t_tap *t)
{
	t->nesting = 0;
	t->plan = 0;
	t->run = 0;
	t->passed = 0;
	g_ft_tprintf("TAP version 13\n");
}
