/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:26:22 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 17:36:46 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_CONVERT_H
# define PF_CONVERT_H

# include <stdarg.h>
# include "ft_streams.h"
# include "priv/pf_defs.h"

/*
** t_conv - conversion function type
** @stream: stream to write to
** @info: info for the conversion
** @args: arguments given to printf
*/
typedef int	(t_conv)(t_stream *stream, t_pf_info *info, va_list args);

/*
** All conversion functions
*/

t_conv		pf_convert_str;

#endif
