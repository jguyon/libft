/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 02:23:20 by jguyon            #+#    #+#             */
/*   Updated: 2017/04/22 15:01:02 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBERS_H
# define FT_NUMBERS_H

/*
** Number functions
*/

/*
** FT_ABS - get the absolute value of a number
** @n: signed number
*/
# define FT_ABS(n) (n < 0 ? -n : n)

/*
** ft_atoi - convert string into int
** @str: string to convert
**
** Will ignore any spaces at the beginning of the string and will
** stop at the first non-digit character
*/
int		ft_atoi(const char *str);

/*
** ft_itoa - convert int to a new string
** @n: int to convert
*/
char	*ft_itoa(int n);

#endif
