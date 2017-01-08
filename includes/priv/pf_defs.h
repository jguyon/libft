/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:08:17 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/08 17:22:10 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_DEFS_H
# define PF_DEFS_H

/*
** Prefix character of conversions
*/
# define PF_CONV_PREFIX '%'

/*
** Structure containing all information about a conversion
*/
typedef struct	s_pf_info {
	char	spec;
}				t_pf_info;

#endif
