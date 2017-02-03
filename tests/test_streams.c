/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_streams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:16:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 21:34:28 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"
#include "ft_memory.h"
#include "ft_strings.h"

static char		g_output[4096] = {0};

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

static void		test_fwrite(t_tap *t)
{
	t_stream	*stm;

	ft_tap_plan(t, 2);
	stm = ft_fopencookie(g_output, g_output_funs);
	FT_TAP_UEQ(t, ft_fwrite("hello world", 11, stm), 11);
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "hello world");
	ft_fclose(stm);
}

static void		test_fputc(t_tap *t)
{
	t_stream	*stm;

	ft_tap_plan(t, 2);
	stm = ft_fopencookie(g_output, g_output_funs);
	FT_TAP_UEQ(t, ft_fputc('h', stm), 'h');
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "h");
	ft_fclose(stm);
}

static void		test_fputs(t_tap *t)
{
	t_stream	*stm;

	ft_tap_plan(t, 2);
	stm = ft_fopencookie(g_output, g_output_funs);
	FT_TAP_UEQ(t, ft_fputs("hello, world", stm), 12);
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "hello, world");
	ft_fclose(stm);
}

static void		test_setbuffer(t_tap *t)
{
	t_stream	*stm;
	char		buff[4];

	ft_tap_plan(t, 4);
	stm = ft_fopencookie(g_output, g_output_funs);
	FT_TAP_NOTOK(t, ft_setbuffer(stm, buff, 4));
	ft_fputs("hello, world", stm);
	FT_TAP_OK(t, ft_setbuffer(stm, buff, 4));
	FT_TAP_SEQ(t, g_output, "hello, w");
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "hello, world");
	ft_fclose(stm);
}

void			test_streams(t_tap *t)
{
	FT_TAP_TEST(t, test_fwrite);
	FT_TAP_TEST(t, test_fputc);
	FT_TAP_TEST(t, test_fputs);
	FT_TAP_TEST(t, test_setbuffer);
}
