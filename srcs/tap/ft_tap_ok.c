/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tap_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:24:51 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/01 23:27:25 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"

int		ft_tap_ok(t_tap *t, int val, const char *msg)
{
	if (!msg)
		msg = "is truthy";
	if (val)
		ft_tap_pass(t, msg);
	else
		ft_tap_fail(t, msg);
	return (val);
}
