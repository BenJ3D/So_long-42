/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/10 04:53:29 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// t_list	*ft_lstnew(char *content)
// {
// 	t_list	*tmp;

// 	tmp = (t_list *)malloc(sizeof(*tmp));
// 	if (!tmp)
// 		return (NULL);
// 	tmp->content = content;
// 	tmp->next = NULL;
// 	return (tmp);
// }

// void	ft_lstadd_back(t_list **alst, t_list *new)
// {
// 	t_list	*lst1;

// 	if (*alst == NULL)
// 		*alst = new;
// 	else if (alst != NULL && new != NULL)
// 	{
// 		lst1 = ft_lstlast(*alst);
// 		lst1->next = new;
// 	}
// }


int main()
{
	t_list	*list;
	t_list	*new;
	t_list	*firstelem;
	
	list = NULL;
	//firstelem = NULL;
	
	//firstelem = list->next;

	new = ft_lstnew("1");
	ft_lstadd_back(&firstelem, new);
	new = ft_lstnew("C");
	ft_lstadd_back(&firstelem, new);
	new = ft_lstnew("P\n");
	ft_lstadd_back(&firstelem, new);

	list = firstelem;
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
	}
	list = firstelem;
	ft_lstdelone()
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
	}
	return (0);
}