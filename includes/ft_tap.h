/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:58:58 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 11:37:02 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAP_H
# define FT_TAP_H

# include <stddef.h>
# include <stdarg.h>
# include <inttypes.h>

# define DO_STR(token) #token
# define STR(token) DO_STR(token)

# define FT_TAP_DIAG "stack", "%s", __FILE__ ":" STR(__LINE__), NULL
# define FT_TAP_TEST(t, tst) ft_tap_test(t, &tst, #tst)
# define FT_TAP_OK(t, e) ft_tap_ok(t, e, #e" is truthy", FT_TAP_DIAG)
# define FT_TAP_NOTOK(t, e) ft_tap_ok(t, !(e), #e" is falsey", FT_TAP_DIAG)
# define FT_TAP_IEQ(t, a, b) ft_tap_ieq(t, a, b, #a" == "#b, FT_TAP_DIAG)

int				(*g_ft_tprintf)(const char *format, ...);
int				(*g_ft_tvprintf)(const char *format, va_list args);

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
void			ft_tap_diag(t_tap *t, va_list args, ...);
void			ft_tap_plan(t_tap *t, size_t n);
int				ft_tap_test(t_tap *t, void (*test)(t_tap *s), const char *msg);
int				ft_tap_ok(t_tap *t, int val, const char *msg, ...);
int				ft_tap_ieq(t_tap *t, intmax_t actual, intmax_t expected,
					const char *msg, ...);

#endif
