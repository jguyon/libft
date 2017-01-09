/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:41:44 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/09 16:57:19 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static size_t			fd_write(void *fd, const char *buff, size_t count)
{
	return (write(*((int *)fd), buff, count));
}

static t_stream_funs	g_fd_funs = {
	&fd_write,
	NULL,
};

int						ft_vdprintf(int fd, const char *format, va_list args)
{
	t_stream	*stream;
	int			res;

	if (!(stream = ft_fopencookie(&fd, g_fd_funs)))
		return (-1);
	res = ft_vfprintf(stream, format, args);
	if (ft_fclose(stream))
		res = -1;
	return (res);
}
