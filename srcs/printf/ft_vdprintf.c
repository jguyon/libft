/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:41:44 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/08 19:43:32 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static ssize_t			fd_write(void *fd, const char *buff, size_t count)
{
	return (write(*((int *)fd), buff, count));
}

static t_stream_funs	fd_funs = {
	.write = &fd_write,
};

int						ft_vdprintf(int fd, const char *format, va_list args)
{
	t_stream		*stm;
	int				res;

	if (!(stm = ft_fopencookie(&fd, "w", fd_funs)))
		return (-1);
	res = ft_vfprintf(stm, format, args);
	if (ft_fclose(stm) == FT_EOF || res < 0)
		return (-1);
	return (res);
}
