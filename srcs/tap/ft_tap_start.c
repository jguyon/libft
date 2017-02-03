/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:05:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 15:27:40 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"
#include "ft_printf.h"
#include "ft_strings.h"

int		(*g_ft_tprintf)(const char *, ...) = &ft_printf;
int		(*g_ft_tvprintf)(const char *, va_list) = &ft_vprintf;
size_t	(*g_ft_tstrlen)(const char *) = &ft_strlen;
int		(*g_ft_tstrcmp)(const char *, const char *) = &ft_strcmp;

void	ft_tap_start(t_tap *t)
{
	t->nesting = 0;
	t->plan = 0;
	t->run = 0;
	t->passed = 0;
	g_ft_tprintf("TAP version 13\n");
}
