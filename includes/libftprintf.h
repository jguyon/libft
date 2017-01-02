/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:46:47 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/02 03:27:06 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_fprintf(t_stream *stream, const char *format, ...);
int		ft_vfprintf(t_stream *stream, const char *format, va_list ap);

#endif
