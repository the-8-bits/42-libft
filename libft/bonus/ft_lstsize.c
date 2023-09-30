#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int count = 0;  // Initialize count to 0

	while (list)
	{
		list = list->next;
		count++;  // Increment the count for each node
	}

	return (count);  // Return the total count
}