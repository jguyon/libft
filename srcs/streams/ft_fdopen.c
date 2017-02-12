/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdopen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:10:09 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/12 18:19:14 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_streams.h"
#include <unistd.h>

static ssize_t			fd_write(void *fd, const char *buff, size_t size)
{
	return (write(*((int *)fd), buff, size));
}

static int				fd_close(void *fd)
{
	return (close(*((int *)fd)));
}

static t_stream_funs	g_fd_funs = {
	.write = &fd_write,
	.close = &fd_close,
};

t_stream				*ft_fdopen(int fd, const char *mode)
{
	t_stream	*stm;

	if (fd < 0 || !(stm = ft_fopencookie(NULL, mode, g_fd_funs)))
		return (NULL);
	stm->fd = fd;
	return (stm);
}
