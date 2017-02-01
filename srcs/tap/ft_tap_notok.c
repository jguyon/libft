/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_notok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:27:52 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/01 23:29:01 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

int		ft_tap_notok(t_tap *t, int val, const char *msg)
{
	if (!msg)
		msg = "is falsy";
	return (ft_tap_ok(t, !val, msg));
}
