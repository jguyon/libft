/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:02:31 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/08 22:03:48 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_memory.h"

static ssize_t			str_write(void *strp, const char *buff, size_t count)
{
	char	**range;

	if (!strp)
		return (count);
	range = (char **)strp;
	if ((size_t)(range[1] - range[0]) > count)
	{
		ft_memcpy(range[0], buff, count);
		range[0] += count;
	}
	else
	{
		ft_memcpy(range[0], buff, range[1] - range[0]);
		range[0] = range[1];
	}
	return (count);
}

static int				str_close(void *strp)
{
	char	**range;

	if (!strp)
		return (0);
	range = (char **)strp;
	if ((size_t)(range[1] - range[0]) > 0)
		range[0][0] = '\0';
	return (0);
}

static t_stream_funs	str_funs = {
	.write = &str_write,
	.close = &str_close,
};

int						ft_vsnprintf(char *str, size_t size,
							const char *format, va_list args)
{
	t_stream	*stm;
	char		*range[2];
	int			res;

	if (size > 0 && !str)
		return (-1);
	if (str)
	{
		range[0] = str;
		range[1] = str + size;
		stm = ft_fopencookie(range, "w", str_funs);
	}
	else
		stm = ft_fopencookie(range, "w", str_funs);
	if (!stm)
		return (-1);
	res = ft_vfprintf(stm, format, args);
	if (ft_fclose(stm) || res < 0)
		return (-1);
	return (res);
}
