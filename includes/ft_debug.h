/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:42:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/03/29 14:53:30 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

/*
** FT_DEBUG_FD - file descriptor for debug messages
*/
# define FT_DEBUG_FD 2

/*
** FT_DEBUG_FMT - printf debug format and args
** @fl: file name
** @ln: line number
** @msg: debug message
*/
# define FT_DEBUG_FMT(fl, ln, msg) "debug: %s (%s:%d)\n", msg, fl, ln

/*
** FT_ASSERT_EXIT - exit status of the program for failed assertions
*/
# define FT_ASSERT_EXIT 2

/*
** FT_DEBUG - print a debug message
** @fmt: printf style format
** @...: format arguments
*/
void	ft_debug(const char *file, int line, const char *fmt, ...);
# define FT_DEBUG(fmt, ...) ft_debug(__FILE__, __LINE__, fmt, ##__VA_ARGS__)

/*
** FT_ASSERT - exit program if a condition is not met
** @expr: expression to check
*/
void	ft_assert(const char *file, int line, const char *expr);
# define FT_ASSERT(expr) ft_assert(__FILE__, __LINE__, (expr) ? NULL : #expr)

#endif
