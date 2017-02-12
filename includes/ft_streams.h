/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streams.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:17:31 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/12 17:55:08 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAMS_H
# define FT_STREAMS_H

/*
** Buffered output stream implementation
*/

# include <stdlib.h>

# define FT_BUFSIZ 1024
# define FT_IONBF 1
# define FT_IOFBF 2
# define FT_EOF -1
# define FT_FOPEN_MAX 16

typedef ssize_t	t_stream_write(void *cookie, const char *buff, size_t size);
typedef int		t_stream_close(void *cookie);

typedef struct	s_stream_funs {
	t_stream_write	*write;
	t_stream_close	*close;
}				t_stream_funs;

typedef struct	s_stream {
	int				mode;
	int				error;
	int				allocated;
	int				fd;
	void			*cookie;
	t_stream_write	*write;
	t_stream_close	*close;
	size_t			size;
	char			*curr;
	char			*buff;
}				t_stream;

t_stream		*g_ft_stdout;
t_stream		*g_ft_stderr;
# define FT_STDOUT	g_ft_stdout
# define FT_STDERR	g_ft_stderr

t_stream		*ft_fmemopen(void *buf, size_t size, const char *mode);
t_stream		*ft_fopencookie(void *cookie, const char *mode,
					t_stream_funs type);
t_stream		*ft_open_memstream(char **ptr, size_t *sizeloc);
int				ft_setvbuf(t_stream *stm, char *buff, int mode, size_t size);
size_t			ft_fwrite(const void *mem, size_t size, size_t n,
					t_stream *stm);
int				ft_fputc(int c, t_stream *stm);
int				ft_fputs(const char *s, t_stream *stm);
int				ft_ferror(t_stream *stm);
void			ft_clearerr(t_stream *stm);
int				ft_fflush(t_stream *stm);
int				ft_fclose(t_stream *stm);
int				ft_fcloseall(void);

t_stream		g_ft_streams[FT_FOPEN_MAX];

typedef struct	s_mem_cookie {
	int			allocated;
	size_t		size;
	void		*buff;
	char		*curr;
}				t_mem_cookie;

typedef struct	s_ptr_cookie {
	size_t		*sizeloc;
	char		**ptr;
	size_t		fullsize;
}				t_ptr_cookie;

#endif
