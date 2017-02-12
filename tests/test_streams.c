/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_streams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:16:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/12 18:38:05 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "ft_streams.h"
#include "ft_memory.h"
#include "ft_strings.h"
#include <fcntl.h>
#include <stdio.h>

static char		g_output[4096] = {0};

static ssize_t	write_to_str(void *cookie, const char *buff, size_t size)
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
	&close_str,
};

static void		test_fwrite(t_tap *t)
{
	t_stream	*stm;

	ft_tap_plan(t, 2);
	stm = ft_fopencookie(g_output, "w", g_output_funs);
	FT_TAP_UEQ(t, ft_fwrite("hello world", 1, 11, stm), 11);
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "hello world");
	ft_fclose(stm);
}

static void		test_fputc(t_tap *t)
{
	t_stream	*stm;

	ft_tap_plan(t, 2);
	stm = ft_fopencookie(g_output, "w", g_output_funs);
	FT_TAP_UEQ(t, ft_fputc('h', stm), 'h');
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "h");
	ft_fclose(stm);
}

static void		test_fputs(t_tap *t)
{
	t_stream	*stm;

	ft_tap_plan(t, 2);
	stm = ft_fopencookie(g_output, "w", g_output_funs);
	FT_TAP_OK(t, ft_fputs("hello, world", stm) >= 0);
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "hello, world");
	ft_fclose(stm);
}

static void		test_setbuffer(t_tap *t)
{
	t_stream	*stm;
	char		buff[4];

	ft_tap_plan(t, 10);
	stm = ft_fopencookie(g_output, "w", g_output_funs);
	FT_TAP_NOTOK(t, ft_setvbuf(stm, buff, FT_IOFBF, 4));
	ft_fputs("hello, world", stm);
	FT_TAP_OK(t, ft_setvbuf(stm, buff, FT_IOFBF, 4));
	FT_TAP_SEQ(t, g_output, "hello, w");
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "hello, world");
	ft_fclose(stm);
	stm = ft_fopencookie(g_output, "w", g_output_funs);
	FT_TAP_NOTOK(t, ft_setvbuf(stm, NULL, FT_IOFBF, 2 * FT_BUFSIZ));
	ft_fputs("hello, world", stm);
	FT_TAP_OK(t, ft_setvbuf(stm, NULL, FT_IOFBF, 2 * FT_BUFSIZ));
	FT_TAP_SEQ(t, g_output, "");
	ft_fflush(stm);
	FT_TAP_SEQ(t, g_output, "hello, world");
	ft_fclose(stm);
	stm = ft_fopencookie(g_output, "w", g_output_funs);
	FT_TAP_NOTOK(t, ft_setvbuf(stm, NULL, FT_IONBF, 0));
	ft_fputs("hello, world", stm);
	FT_TAP_SEQ(t, g_output, "hello, world");
	ft_fclose(stm);
}

static void		test_fcloseall(t_tap *t)
{
	t_stream	*stm;
	t_stream	out;
	t_stream	err;

	out = *FT_STDOUT;
	err = *FT_STDERR;
	ft_tap_plan(t, 5);
	FT_TAP_OK(t, (int)(stm = ft_fopencookie(g_output, "w", g_output_funs)));
	ft_fputs("hello, world", stm);
	FT_TAP_SEQ(t, g_output, "");
	FT_TAP_NOTOK(t, ft_fcloseall());
	FT_TAP_OK(t, ft_ferror(FT_STDOUT));
	FT_TAP_OK(t, ft_ferror(FT_STDERR));
	*FT_STDOUT = out;
	*FT_STDERR = err;
}

static void		test_fmemopen(t_tap *t)
{
	t_stream	*stm;
	char		buff[256];

	FT_TAP_OK(t, (int)(stm = ft_fmemopen(buff, sizeof(buff), "w")));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	FT_TAP_IEQ(t, ft_fputs("hello", stm), 0);
	FT_TAP_IEQ(t, ft_fputs(", world", stm), 0);
	ft_fclose(stm);
	FT_TAP_SEQ(t, buff, "hello, world");
	ft_bzero(buff, 4);
	FT_TAP_OK(t, (int)(stm = ft_fmemopen(buff, 4, "w")));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	FT_TAP_IEQ(t, ft_fputs("hell", stm), 0);
	FT_TAP_SEQ(t, buff, "hello, world");
	FT_TAP_IEQ(t, ft_fputs("o", stm), FT_EOF);
	ft_fclose(stm);
	FT_TAP_OK(t, (int)(stm = ft_fmemopen(NULL, 256, "w")));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	FT_TAP_IEQ(t, ft_fputs("hello, world", stm), 0);
	ft_fclose(stm);
}

static void		test_memstream(t_tap *t)
{
	t_stream	*stm;
	char		*ptr;
	size_t		size;

	FT_TAP_OK(t, (int)(stm = ft_open_memstream(&ptr, &size)));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	ft_fputs("hello", stm);
	FT_TAP_UEQ(t, size, 5);
	FT_TAP_SEQ(t, ptr, "hello");
	ft_fputs(", world", stm);
	FT_TAP_UEQ(t, size, 12);
	FT_TAP_SEQ(t, ptr, "hello, world");
	ft_fclose(stm);
	free(ptr);
}

static void		test_fdopen(t_tap *t)
{
	int			fd;
	t_stream	*stm;
	FILE		*file;
	char		buff[256];

	FT_TAP_NOTOK(t,
		(fd = open("/tmp/libft_testfile", O_RDWR | O_CREAT | O_TRUNC)) < 0);
	FT_TAP_OK(t, (int)(stm = ft_fdopen(fd, "w")));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	FT_TAP_IEQ(t, ft_fputs("hello, world\n", stm), 0);
	FT_TAP_IEQ(t, ft_fclose(stm), 0);
	file = fopen("/tmp/libft_testfile", "r");
	fgets(buff, sizeof(buff), file);
	FT_TAP_SEQ(t, buff, "hello, world\n");
	fclose(file);
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_fwrite);
	FT_TAP_TEST(t, test_fputc);
	FT_TAP_TEST(t, test_fputs);
	FT_TAP_TEST(t, test_setbuffer);
	FT_TAP_TEST(t, test_fcloseall);
	FT_TAP_TEST(t, test_fmemopen);
	FT_TAP_TEST(t, test_memstream);
	FT_TAP_TEST(t, test_fdopen);
}
