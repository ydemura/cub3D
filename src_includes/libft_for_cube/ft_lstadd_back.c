/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: julia <julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:37:36 by julia         #+#    #+#                 */
/*   Updated: 2020/11/11 19:24:51 by julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element_of_lst;

	if (*lst && new)
	{
		last_element_of_lst = ft_lstlast(*lst);
		last_element_of_lst->next = new;
		new->next = 0;
	}
	else if (!*lst)
	{
		*lst = new;
		new->next = 0;
	}
}
