/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:30:18 by jguyon            #+#    #+#             */
/*   Updated: 2017/01/02 02:39:02 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <wchar.h>
# include <inttypes.h>
# include "libft/ft_memory.h"
# include "libft/ft_strings.h"
# include "libft/ft_chars.h"
# include "libft/ft_numbers.h"
# include "libft/ft_simpleio.h"
# include "libft/ft_unicode.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_lstfoldl(t_list *lst, void *acc,
									void *(*f)(t_list *elem, void *acc));
void				*ft_lstfoldr(t_list *lst, void *acc,
									void *(*f)(t_list *elem, void *acc));
void				ft_lstsort(t_list **lst, int (*f)(t_list *e1, t_list *e2));
void				ft_lstmsort(t_list **lst, int (*f)(t_list *e1, t_list *e2));
void				ft_lstdelcnt(void *content, size_t size);

#endif
