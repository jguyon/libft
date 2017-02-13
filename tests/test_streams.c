/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_streams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:16:23 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/13 22:01:19 by jguyon           ###   ########.fr       */
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

static ssize_t	read_from_str(void *cookie, char *buff, size_t size)
{
	size_t	len;

	len = ft_strlen(cookie);
	size = size > len ? len : size;
	ft_memcpy(buff, cookie, size);
	ft_memmove(cookie, cookie + size, sizeof(g_output) - size);
	return (size);
}

static int		close_str(void *cookie)
{
	ft_strclr(cookie);
	return (0);
}

static t_stream_funs	g_output_funs = {
	.write = &write_to_str,
	.read = &read_from_str,
	.close = &close_str,
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

static void		test_fread(t_tap *t)
{
	t_stream	*stm;
	char		str[256] = {0};

	ft_strcpy(g_output, "hello, world");
	stm = ft_fopencookie(g_output, "r", g_output_funs);
	FT_TAP_UEQ(t, ft_fread(str, 1, sizeof(str), stm), 12);
	FT_TAP_SEQ(t, str, "hello, world");
	FT_TAP_IEQ(t, ft_feof(stm), FT_EOF);
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

static void		test_fgetc(t_tap *t)
{
	t_stream	*stm;

	ft_strcpy(g_output, "hello");
	stm = ft_fopencookie(g_output, "r", g_output_funs);
	FT_TAP_IEQ(t, ft_fgetc(stm), 'h');
	FT_TAP_IEQ(t, ft_fgetc(stm), 'e');
	FT_TAP_IEQ(t, ft_fgetc(stm), 'l');
	FT_TAP_IEQ(t, ft_fgetc(stm), 'l');
	FT_TAP_IEQ(t, ft_fgetc(stm), 'o');
	FT_TAP_IEQ(t, ft_fgetc(stm), FT_EOF);
	FT_TAP_IEQ(t, ft_feof(stm), FT_EOF);
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

static void		test_fgets(t_tap *t)
{
	t_stream	*stm;
	char		str[256];

	ft_strcpy(g_output, "hello\nworld");
	stm = ft_fopencookie(g_output, "r", g_output_funs);
	FT_TAP_SEQ(t, ft_fgets(str, sizeof(str), stm), "hello\n");
	FT_TAP_SEQ(t, ft_fgets(str, sizeof(str), stm), "world");
	FT_TAP_IEQ(t, ft_feof(stm), FT_EOF);
	ft_fclose(stm);
}

static void		test_fflush(t_tap *t)
{
	t_stream	*stm1;
	t_stream	*stm2;
	char		out1[256] = {0};
	char		out2[256] = {0};

	stm1 = ft_fopencookie(out1, "w", g_output_funs);
	stm2 = ft_fopencookie(out2, "w", g_output_funs);
	FT_TAP_OK(t, ft_fputs("hello", stm1) >= 0);
	FT_TAP_OK(t, ft_fputs("world", stm2) >= 0);
	FT_TAP_SEQ(t, out1, "");
	FT_TAP_SEQ(t, out2, "");
	FT_TAP_OK(t, ft_fflush(NULL) == 0);
	FT_TAP_SEQ(t, out1, "hello");
	FT_TAP_SEQ(t, out2, "world");
	ft_fclose(stm1);
	ft_fclose(stm2);
}

static void		test_setbuffer(t_tap *t)
{
	t_stream	*stm;
	char		buff[4];
	char		str[256] = {0};

	ft_tap_plan(t, 13);
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
	ft_strcpy(g_output, "hello, world");
	stm = ft_fopencookie(g_output, "r", g_output_funs);
	FT_TAP_NOTOK(t, ft_setvbuf(stm, NULL, FT_IONBF, 0));
	FT_TAP_UEQ(t, ft_fread(str, 1, sizeof(str), stm), 12);
	FT_TAP_SEQ(t, str, "hello, world");
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
	char		str[256] = {0};

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
	FT_TAP_OK(t, (int)(stm = ft_fmemopen("hello, world", 12, "r")));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	FT_TAP_UEQ(t, ft_fread(str, 1, 5, stm), 5);
	FT_TAP_SEQ(t, str, "hello");
	FT_TAP_IEQ(t, ft_feof(stm), 0);
	FT_TAP_UEQ(t, ft_fread(str + 5, 1, sizeof(str) - 5, stm), 7);
	FT_TAP_SEQ(t, str, "hello, world");
	FT_TAP_IEQ(t, ft_feof(stm), FT_EOF);
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
	char		buff[256] = {0};

	FT_TAP_NOTOK(t,
		(fd = open("/tmp/libft_testfile", O_WRONLY | O_CREAT | O_TRUNC)) < 0);
	FT_TAP_OK(t, (int)(stm = ft_fdopen(fd, "w")));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	FT_TAP_IEQ(t, ft_fputs("hello, world\n", stm), 0);
	FT_TAP_IEQ(t, ft_fclose(stm), 0);
	FT_TAP_NOTOK(t,
				 (fd = open("/tmp/libft_testfile", O_RDONLY)) < 0);
	FT_TAP_OK(t, (int)(stm = ft_fdopen(fd, "r")));
	ft_setvbuf(stm, NULL, FT_IONBF, 0);
	FT_TAP_UEQ(t, ft_fread(buff, 1, sizeof(buff), stm), 13);
	FT_TAP_SEQ(t, buff, "hello, world\n");
	FT_TAP_IEQ(t, ft_fclose(stm), 0);
}

void			run_tests(t_tap *t)
{
	FT_TAP_TEST(t, test_fwrite);
	FT_TAP_TEST(t, test_fread);
	FT_TAP_TEST(t, test_fputc);
	FT_TAP_TEST(t, test_fgetc);
	FT_TAP_TEST(t, test_fputs);
	FT_TAP_TEST(t, test_fgets);
	FT_TAP_TEST(t, test_fflush);
	FT_TAP_TEST(t, test_setbuffer);
	FT_TAP_TEST(t, test_fcloseall);
	FT_TAP_TEST(t, test_fmemopen);
	FT_TAP_TEST(t, test_memstream);
	FT_TAP_TEST(t, test_fdopen);
}
