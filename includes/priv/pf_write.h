/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_write.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:25:34 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 18:40:14 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_WRITE_H
# define PF_WRITE_H

# include "ft_streams.h"

/*
** pf_write_pad - writes padding corresponding to a string
** @stream: stream to write to
** @min_len: min length of the string
** @real_len: actual length of the string
**
** Returns the number of bytes of padding written.
*/
size_t	pf_write_pad(t_stream *stream, size_t min_len, size_t real_len);

#endif
