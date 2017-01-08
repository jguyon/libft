/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streams.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:17:31 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 13:06:44 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAMS_H
# define FT_STREAMS_H

/*
** Buffered output stream implementation
*/

# include <stddef.h>

/*
** FT_BUFF_SIZE - default buffer size of a stream
*/
# define FT_BUFF_SIZE 4096

/*
** t_stream_type - type containing functions used to flush or close the stream
*/
typedef struct	s_stream_type {
	size_t	buff_size;
	size_t	(*write)(void *cookie, const char *buff, size_t size);
	int		(*close)(void *cookie);
}				t_stream_type;

/*
** t_stream - stream type
*/
typedef struct	s_stream {
	void			*cookie;
	char			*curr;
	t_stream_type	type;
	char			*buff;
}				t_stream;

/*
** ft_fopencookie - create a new stream
** @cookie: data passed to @type functions
** @type: description of the stream
*/
t_stream		*ft_fopencookie(void *cookie, t_stream_type type);

/*
** ft_fwrite - write characters to a stream
** @s: buffer of characters
** @count: number of bytes
** @stream: stream to write to
**
** Returns the number bytes written
*/
size_t			ft_fwrite(const char *s, size_t count, t_stream *stream);

/*
** ft_fputc - write a character to a stream
** @c: character to write
** @stream: stream to write to
**
** Returns the value written if successful, a negative number otherwise.
*/
int				ft_fputc(int c, t_stream *stream);

/*
** ft_fputs - write a string to a stream
** @s: string to write
** @stream: stream to write to
**
** Returns the number of bytes written if successful,
** a negative number otherwise.
*/
int				ft_fputs(const char *s, t_stream *stream);

/*
** ft_ferror - check if a stream has suffered an error
** @stream: stream to test
*/
int				ft_ferror(t_stream *stream);

/*
** ft_fclose - flush and close a stream
** @stream: stream to close
**
** Returns a positive or null number if successful, a negative number otherwise.
*/
int				ft_fclose(t_stream *stream);

/*
** ft_fflush - flush buffer of a stream
** @stream - stream to flush
**
** Returns a zero if the buffer was empty, a positive number if flushing
** was successful, a negative number otherwise.
*/
int				ft_fflush(t_stream *stream);

#endif
