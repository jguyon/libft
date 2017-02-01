/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:58:58 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/01 23:41:44 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAP_H
# define FT_TAP_H

# include <stddef.h>

int				(*g_ft_tprintf)(const char *format, ...);

typedef struct	s_tap {
	size_t		nesting;
	size_t		plan;
	size_t		run;
	size_t		passed;
}				t_tap;

void			ft_tap_start(t_tap *t);
void			ft_tap_end(t_tap *t);
void			ft_tap_pass(t_tap *t, const char *msg);
void			ft_tap_fail(t_tap *t, const char *msg);
void			ft_tap_plan(t_tap *t, size_t n);
int				ft_tap_test(t_tap *t, void (*test)(t_tap *s), const char *msg);
int				ft_tap_ok(t_tap *t, int val, const char *msg);
int				ft_tap_notok(t_tap *t, int val, const char *msg);

#endif
