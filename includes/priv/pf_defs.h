/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:08:17 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/09 11:19:44 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_DEFS_H
# define PF_DEFS_H

# include <unistd.h>

/*
** Take absolute value of integer
*/
# define PF_ABS(n) ((n) < 0 ? -(n) : (n))

/*
** Prefix character of conversions
*/
# define PF_CONV_PREFIX '%'

/*
** Flag characters
*/
# define PF_FLAG_LEFT	'-'

/*
** Structure representing presence of flags
*/
typedef struct	s_pf_flags {
	unsigned int	left : 1;
}				t_pf_flags;

/*
** Prefix character for precision
*/
# define PF_PREC_PREFIX '.'

/*
** Character for arg width or precision
*/
# define PF_ARG_CHAR '*'

/*
** Length modifiers
*/
# define PF_MOD_L	'l'
# define PF_MOD_H	'h'
# define PF_MOD_J	'j'
# define PF_MOD_Z	'z'

/*
** Type representing a modifier
*/
typedef enum	e_mod {
	NO_MOD,
	HH,
	H,
	L,
	LL,
	J,
	Z
}				t_mod;

/*
** Conversion specifiers
*/
# define PF_STRING_SPEC	's'
# define PF_INT_SPEC	'd'
# define PF_ALTINT_SPEC	'i'
# define PF_UINT_SPEC	'u'

/*
** String to print when null
*/
# define PF_STRING_NULL "(null)"

/*
** Structure containing all information about a conversion
*/
typedef struct	s_pf_info {
	char		spec;
	t_pf_flags	flags;
	ssize_t		min_width;
	ssize_t		prec;
	t_mod		mod;
}				t_pf_info;

#endif
