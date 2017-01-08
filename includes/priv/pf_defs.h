/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:08:17 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 18:54:21 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_DEFS_H
# define PF_DEFS_H

# include <unistd.h>

/*
** Prefix character of conversions
*/
# define PF_CONV_PREFIX '%'

/*
** Prefix character for precision
*/
# define PF_PREC_PREFIX '.'

/*
** Conversion specifiers
*/
# define PF_STRING_SPEC	's'

/*
** String to print when null
*/
# define PF_STRING_NULL "(null)"

/*
** Structure containing all information about a conversion
*/
typedef struct	s_pf_info {
	char	spec;
	size_t	min_width;
	ssize_t	prec;
}				t_pf_info;

#endif
