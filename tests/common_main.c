/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:15:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/02/13 22:45:25 by jguyon           ###   ########.fr       */
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
