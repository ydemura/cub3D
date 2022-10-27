/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: julia <julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:37:36 by julia         #+#    #+#                 */
/*   Updated: 2021/10/01 01:44:53 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last_element_of_new;

	if (*lst && new)
	{
		last_element_of_new = ft_lstlast(new);
		last_element_of_new->next = *lst;
		*lst = new;
	}
	else if (!*lst)
	{
		*lst = new;
		new->next = 0;
	}
}
