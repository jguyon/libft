/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:23:02 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/02 02:21:36 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_chars.h"

int		ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}