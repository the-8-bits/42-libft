#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!f || !del)
		return (NULL);

	first = NULL;
	while (lst)
	{
		void *data = (*f)(lst->content);

		if (!(new_node = ft_lstnew(data)))
		{
			// Free the newly created list and its data if an error occurs
			ft_lstclear(&new_list, del);
			return (NULL);
		}

		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}

	return (new_list);
}