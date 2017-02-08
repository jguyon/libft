/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:31:58 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/08 20:14:46 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_memory.h"

static ssize_t			str_write(void *strp, const char *buff, size_t count)
{
	char	*str;

	str = *((char **)strp);
	if (!str)
		return (count);
	ft_memcpy(str, buff, count);
	strp = str + count;
	return (count);
}

static int				str_close(void *strp)
{
	char	*str;

	str = *((char **)strp);
	if (!str)
		return (0);
	*str = '\0';
	return (0);
}

static t_stream_funs	str_funs = {
	.write = &str_write,
	.close = &str_close,
};

int						ft_vsprintf(char *str, const char *format, va_list args)
{
	t_stream	*stm;
	int			res;

	if (!(stm = ft_fopencookie(&str, "w", str_funs))
		|| ft_setvbuf(stm, NULL, FT_IONBF, 0))
	{
		ft_fclose(stm);
		return (-1);
	}
	res = ft_vfprintf(stm, format, args);
	if (ft_fclose(stm) || res < 0)
		return (-1);
	return (res);
}
