/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:15:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/03 16:27:33 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tap.h"
#include <string.h>
#include <stdio.h>

int		main(void)
{
	t_tap	t;

	ft_tap_start(&t);
	ft_tap_end(&t);
}
