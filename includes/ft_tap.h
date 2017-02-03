/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:58:58 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 13:56:56 by jguyon           ###   ########.fr       */
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
# define FT_TAP_OK(t, e) ft_tap_ok(t, e, #e" is true", FT_TAP_DIAG)
# define FT_TAP_NOTOK(t, e) ft_tap_notok(t, e, #e" is false", FT_TAP_DIAG)
# define FT_TAP_IEQ(t, a, b) ft_tap_ieq(t, a, b, #a" == "#b, FT_TAP_DIAG)
# define FT_TAP_NOTIEQ(t, a, b) ft_tap_notieq(t, a, b, #a" != "#b, FT_TAP_DIAG)
# define FT_TAP_UEQ(t, a, b) ft_tap_ueq(t, a, b, #a" == "#b, FT_TAP_DIAG)
# define FT_TAP_NOTUEQ(t, a, b) ft_tap_notueq(t, a, b, #a" != "#b, FT_TAP_DIAG)
# define FT_TAP_SEQ(t, a, b) ft_tap_seq(t, a, b, #a" == "#b, FT_TAP_DIAG)
# define FT_TAP_NOTSEQ(t, a, b) ft_tap_notseq(t, a, b, #a" != "#b, FT_TAP_DIAG)

int				(*g_ft_tprintf)(const char *format, ...);
int				(*g_ft_tvprintf)(const char *format, va_list args);
size_t			(*g_ft_strlen)(const char *str);
int				(*g_ft_strcmp)(const char *s1, const char *s2);

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
int				ft_tap_notok(t_tap *t, int val, const char *msg, ...);
int				ft_tap_ieq(t_tap *t, intmax_t actual, intmax_t expected,
					const char *msg, ...);
int				ft_tap_notieq(t_tap *t, intmax_t actual, intmax_t expected,
					const char *msg, ...);
int				ft_tap_ueq(t_tap *t, uintmax_t actual, uintmax_t expected,
					const char *msg, ...);
int				ft_tap_notueq(t_tap *t, uintmax_t actual, uintmax_t expected,
					const char *msg, ...);
int				ft_tap_seq(t_tap *t, const char *actual, const char *expected,
					const char *msg, ...);
int				ft_tap_notseq(t_tap *t,
					const char *actual, const char *expected,
					const char *msg, ...);
char			*ft_tap_quote(const char *str);

#endif
