/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_streams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:36:37 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/09 17:47:14 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static char	g_output[4096] = {0};

static size_t	write_to_str(void *cookie, const char *buff, size_t size)
{
	ft_memcpy(cookie + ft_strlen(cookie), buff, size);
	return (size);
}

static int		close_str(void *cookie)
{
	ft_strclr(cookie);
	return (0);
}

static t_stream_funs	g_output_funs = {
	&write_to_str,
	&close_str
};

TFT_TEST(test_streams_fwrite)
{
	t_stream	*stm;

	stm = ft_fopencookie(g_output, g_output_funs);
	TFT_ASSERT(ft_fwrite("hello world", 11, stm) == 11);
	ft_fflush(stm);
	TFT_ASSERT(strcmp(g_output, "hello world") == 0);
	ft_fclose(stm);
}

TFT_TEST(test_streams_fputc)
{
	t_stream	*stm;

	stm = ft_fopencookie(g_output, g_output_funs);
	TFT_ASSERT(ft_fputc('h', stm) == 'h');
	ft_fflush(stm);
	TFT_ASSERT(strcmp(g_output, "h") == 0);
	ft_fclose(stm);
}

TFT_TEST(test_streams_fputs)
{
	t_stream	*stm;

	stm = ft_fopencookie(g_output, g_output_funs);
	TFT_ASSERT(ft_fputs("hello, world", stm) == 12);
	ft_fflush(stm);
	TFT_ASSERT(strcmp(g_output, "hello, world") == 0);
	ft_fclose(stm);
}

TFT_TEST(test_streams_setbuffer)
{
	t_stream	*stm;
	char		buff[4];

	stm = ft_fopencookie(g_output, g_output_funs);
	TFT_ASSERT(!ft_setbuffer(stm, buff, 4));
	ft_fputs("hello, world", stm);
	TFT_ASSERT(ft_setbuffer(stm, buff, 4));
	TFT_ASSERT(strcmp(g_output, "hello, w") == 0);
	ft_fflush(stm);
	TFT_ASSERT(strcmp(g_output, "hello, world") == 0);
	ft_fclose(stm);
}

void	test_streams(void)
{
	TFT_RUN(test_streams_fwrite);
	TFT_RUN(test_streams_fputc);
	TFT_RUN(test_streams_fputs);
	TFT_RUN(test_streams_setbuffer);
}
