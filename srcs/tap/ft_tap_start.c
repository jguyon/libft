/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:05:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/01 23:21:55 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"
#include "ft_printf.h"

int		(*g_printf)(const char *, ...) = &ft_printf;

void	ft_tap_start(t_tap *t)
{
	t->nesting = 0;
	t->plan = 0;
	t->run = 0;
	t->passed = 0;
	g_ft_tprintf("TAP version 13\n");
}
