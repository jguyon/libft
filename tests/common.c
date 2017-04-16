/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 17:36:06 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/16 17:36:07 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include <string.h>
#include <stdio.h>

int		main(void)
{
	t_tap	t;

	ft_tap_start(&t);
	run_tests(&t);
	ft_tap_end(&t);
}
