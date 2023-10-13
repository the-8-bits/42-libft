---
title: Libft - Bonus
tags:
  - "42"
  - programação
  - common_core
use: README, Documentation
languages: 
dependences:
---

> [!INFO] 
>  Copied from [`42Porto`](https://www.42porto.com/) all rights reserved. Modified according to my understanding and to facilitate learning.  
> If you spot something that isn't right, please open an [Issue](https://github.com/the-8-bits/42-libft/issues/new)

- [Bonus](#bonus)
  - [t\_list](#t_list)
  - [t\_split\_next](#t_split_next)
  - [ft\_lstnew](#ft_lstnew)
  - [ft\_lstadd\_front](#ft_lstadd_front)
  - [ft\_lstsize](#ft_lstsize)
  - [ft\_lstlast](#ft_lstlast)
  - [ft\_lstadd\_back](#ft_lstadd_back)
  - [ft\_lstdelone](#ft_lstdelone)
  - [ft\_lstclear](#ft_lstclear)
  - [ft\_lstiter](#ft_lstiter)
  - [ft\_lstmap](#ft_lstmap)

# Bonus

## t_list

This `t_list` structure is often used to create linked lists in C, where each node of the list contains two components:

1. `void *content`: This member is a pointer to the actual data or content stored in the node. The use of `void *` allows this linked list to hold data of different types, as a `void *` can be type-casted to any data type. The specific type of data stored in this member depends on how the linked list is used.

2. `struct s_list *next`: This member is a pointer to the next node in the linked list. It is used to link the nodes together, forming a chain of elements.

Here's a breakdown of the members of the `t_list` structure:

- `content`: This member stores the actual data or content associated with a particular node. It is often used to store values or data structures of various types, such as integers, strings, custom structures, or pointers to other data.

- `next`: This member is a pointer to the next node in the linked list. It allows you to navigate from one node to the next in the list. When working with linked lists, you can traverse the list by following these `next` pointers.

Linked lists are commonly used in C for dynamic data storage because they can grow or shrink as needed, unlike arrays with fixed sizes. They are especially useful when you need to insert or delete elements in the middle of the list efficiently.

> [!INFO]
> Here's a simple example of how you might create and use a linked list with this `t_list` structure: it creates three nodes, assigns integer data to them, links them together, and then traverses and prints the data stored in each node. Finally, it frees the memory allocated for the nodes.
> 
>```c
>#include <stdio.h>
>#include <stdlib.h>
>
>typedef struct s_list
>{
>    void *content;
>    struct s_list *next;
>} t_list;
>
>int main()
>{
>    // Create nodes for the linked list
>    t_list *node1 = malloc(sizeof(t_list));
>    t_list *node2 = malloc(sizeof(t_list));
>    t_list *node3 = malloc(sizeof(t_list));
>
>    // Assign content to the nodes
>    int data1 = 42;
>    int data2 = 17;
>    int data3 = 99;
>
>    node1->content = &data1;
>    node2->content = &data2;
>    node3->content = &data3;
>
>    // Link the nodes together
>    node1->next = node2;
>    node2->next = node3;
>    node3->next = NULL; // The last node has no next node
>
>    // Traverse and print the linked list
>    t_list *current = node1;
>    while (current != NULL)
>    {
>        int *current_data = (int *)(current->content);
>        printf("%d\n", *current_data);
>        current = current->next;
>    }
>
>    // Free memory for the nodes
>    free(node1);
>    free(node2);
>    free(node3);
>
>    return 0;
>}
>```

## t_split_next

The `t_split_next` structure you've provided is a data structure used to store information about the start and length of a substring or segment within a larger string. It typically serves as a data structure to represent substrings extracted from a larger string during string processing or parsing operations. Is particularly useful when working with text processing tasks where you need to manipulate and extract substrings from a larger text or data.

Here's a breakdown of the members of the `t_split_next` structure:

- `size_t start`: This member represents the starting position or index of the substring within the larger string. It is typically the position where the substring begins in the original string.

- `size_t length`: This member represents the length of the substring. It indicates the number of characters or elements that make up the substring starting from the `start` position.

`size_t` is used for both `start` and `length` because it is an unsigned integer type that can represent non-negative values, making it suitable for indexing and specifying lengths.

> [!INFO]
> In this example, the `t_split_next` structure is used to define a substring within the original string "Hello, World!" starting from position 7 (the 'W' character) with a length of 6 characters ("World!"). The program then extracts and prints the substring based on the information stored in the `t_split_next` structure.
>
>```c
>#include <stdio.h>
>#include <string.h>
>
>typedef struct s_split_next
>{
>    size_t start;
>    size_t length;
>} t_split_next;
>
>int main()
>{
>    // Example string
>    const char *originalString = "Hello, World!";
>    
>    // Define a substring using t_split_next
>    t_split_next substring;
>    substring.start = 7;    // Start position of "World!"
>    substring.length = 6;   // Length of "World!"
>
>    // Extract and print the substring
>    printf("Substring: ");
>    for (size_t i = 0; i < substring.length; i++)
>    {
>        putchar(originalString[substring.start + i]);
>    }
>    printf("\n");
>
>    return 0;
>}
>```

## [ft_lstnew](../libft/ft_lstnew.c)

The `ft_lstnew` function is used to create a new node for a singly-linked list. It allocates memory for the node, assigns the provided content to the node's `content` field, and initializes the `next` field to `NULL`. This function is typically used when you want to add a new element to the beginning of a linked list.

Here's a breakdown of how the `ft_lstnew` function works:

- `void *content`: The `content` argument represents the data or content you want to store in the newly created node. The `void *` type allows this function to handle content of various data types.

- The function begins by attempting to allocate memory for a new node using `malloc`. If memory allocation fails, it returns `NULL` to indicate an error.

- If memory allocation is successful, it initializes a pointer `new_node` to point to the newly allocated memory.

- It assigns the provided `content` pointer to the `content` field of the newly created node. This means that the `content` field of the new node will point to the same data that the `content` argument points to.

- It sets the `next` field of the new node to `NULL`, indicating that it's the last node in the list (at this point, it's a standalone node).

- Finally, it returns a pointer to the newly created node, which can be used to add this node to a linked list or manipulate it further.

## [ft_lstadd_front](../libft/ft_lstadd_front.c)

The `ft_lstadd_front` function is used to add a new node to the front (beginning) of a singly-linked list. It takes two arguments:

1. `t_list **alst`: A pointer to a pointer to the head of the linked list. The double pointer (`**alst`) is used to modify the original pointer to the head of the list if necessary.

2. `t_list *new`: A pointer to the new node that you want to add to the front of the list.

Here's a breakdown of how the `ft_lstadd_front` function works:

- It first checks if the `alst` pointer is not `NULL`. This check ensures that the function won't attempt to modify a non-existent list (a `NULL` list).

- Inside the first conditional block (`if (alst)`), it checks if the double pointer `*alst` is not `NULL`. This check verifies whether the list already contains nodes (i.e., the head pointer is not `NULL`).

- If the list is not empty (i.e., `*alst` is not `NULL`), it updates the `next` pointer of the new node `new` to point to the current head of the list (`*alst`). This step ensures that the new node becomes the new head of the list, and it links the rest of the list to the new node.

- Finally, it updates the head pointer `*alst` to point to the `new` node, making the `new` node the new head of the list.

## [ft_lstsize](../libft/ft_lstsize.c)

The `ft_lstsize` function is used to calculate and return the number of nodes (elements) in a singly-linked list. It takes a pointer to the head of the list (`t_list *lst`) as its argument and returns an integer representing the size of the list.

Here's a breakdown of how the `ft_lstsize` function works:

- It initializes a variable `count` to 0. This variable will be used to keep track of the number of nodes in the list.

- The function enters a `while` loop that continues as long as the `lst` pointer is not `NULL`. This loop is used to traverse the linked list.

- Inside the loop, the function advances the `lst` pointer to the next node in the list by setting `lst` to `lst->next`. This effectively moves to the next node in the list.

- For each node visited in the loop, the `count` variable is incremented by 1. This counts the number of nodes visited so far.

- Once the loop has traversed the entire list (i.e., when `lst` becomes `NULL`), the function exits the loop.

- Finally, the function returns the value of the `count` variable, which represents the total number of nodes in the linked list.

**It's important to note that the `ft_lstsize` function does not modify the linked list in any way; it simply counts the nodes.**

> [!INFO]
> Here's an example of how you might use the `ft_lstsize` function:
> 
>```c
>int main()
>{
>    // Create a linked list with three nodes
>    t_list *head = NULL;
>
>    // Add nodes to the list
>    t_list *node1 = malloc(sizeof(t_list));
>    t_list *node2 = malloc(sizeof(t_list));
>    t_list *node3 = malloc(sizeof(t_list));
>
>    node1->next = node2;
>    node2->next = node3;
>    node3->next = NULL;
>
>    // Calculate the size of the linked list
>    int size = ft_lstsize(head);
>
>    printf("Size of the linked list: %d\n", size);
>
>    // Free memory allocated for the nodes
>    free(node1);
>    free(node2);
>    free(node3);
>
>    return (0);
>}
>```

## [ft_lstlast](../libft/ft_lstlast.c)

The `ft_lstlast` function is used to find and return a pointer to the last node in a singly-linked list. It takes a pointer to the head of the list (`t_list *lst`) as its argument and returns a pointer to the last node in the list. If the list is empty (i.e., `lst` is `NULL`), the function returns `NULL`.

Here's a breakdown of how the `ft_lstlast` function works:

- The function enters a `while` loop that continues as long as the `lst` pointer is not `NULL`. This loop is used to traverse the linked list.

- Inside the loop, the function checks whether the `lst->next` pointer is `NULL`. If it is, it means that the current node (`lst`) is the last node in the list.

- If the current node is indeed the last node, the function immediately returns a pointer to that node, effectively indicating that it is the last node in the list.

- If the current node is not the last node, the function advances the `lst` pointer to the next node in the list by setting `lst` to `lst->next`. This effectively moves to the next node in the list and continues the loop.

- Once the loop has traversed the entire list (i.e., when `lst` becomes `NULL`), the function exits the loop.

- If the loop completes without finding the last node (i.e., when the list is empty), the function returns `NULL` to indicate that there is no last node.

> [!INFO]
> Here's an example of how you might use the `ft_lstlast` function, it's used to find and print the content of the last node in a linked list with three nodes. If the list is empty, it prints a message indicating that the list is empty.:
> 
>```c
>int main()
>{
>    // Create a linked list with three nodes
>    t_list *head = NULL;
>
>    // Add nodes to the list
>    t_list *node1 = malloc(sizeof(t_list));
>    t_list *node2 = malloc(sizeof(t_list));
>    t_list *node3 = malloc(sizeof(t_list));
>
>    node1->next = node2;
>    node2->next = node3;
>    node3->next = NULL;
>
>    // Find the last node in the linked list
>    t_list *last_node = ft_lstlast(head);
>
>    if (last_node)
>    {
>        printf("Content of the last node: %p\n", last_node->content);
>    }
>    else
>    {
>        printf("The list is empty.\n");
>    }
>
>    // Free memory allocated for the nodes
>    free(node1);
>    free(node2);
>    free(node3);
>
>    return (0);
>}
>```

## [ft_lstadd_back](../libft/ft_lstadd_back.c)

The `ft_lstadd_back` function is used to add a new node to the end (tail) of a singly-linked list. It takes two arguments:

1. `t_list **alst`: A pointer to a pointer to the head of the linked list. The double pointer (`**alst`) is used to modify the original pointer to the head of the list if necessary.

2. `t_list *new`: A pointer to the new node that you want to add to the end of the list.

Here's a breakdown of how the `ft_lstadd_back` function works:

- It first checks if the `alst` pointer is not `NULL`. This check ensures that the function won't attempt to modify a non-existent list (a `NULL` list).

- Inside the first conditional block (`if (alst)`), it checks if the double pointer `*alst` is not `NULL`. This check verifies whether the list already contains nodes (i.e., the head pointer is not `NULL`).

- If the list is not empty (i.e., `*alst` is not `NULL`), it calls the `ft_lstlast` function to find the last node in the list and assigns the result to the `last` pointer. The `last` pointer now points to the current last node in the list.

- It then updates the `next` pointer of the current last node (`last->next`) to point to the `new` node. This effectively adds the `new` node to the end of the list by making it the new last node.

- If the list is empty (i.e., `*alst` is `NULL`), it simply assigns the `new` node to the `*alst` pointer, making the `new` node the head of the list.

> [!INFO]
> Here's an example of how you might use the `ft_lstadd_back` function, it's used to add two new nodes to the end of a linked list. The program then prints the contents of the linked list to verify that the new nodes have been added to the end. Finally, it frees the memory allocated for the nodes.:
> 
>```c
>int main()
>{
>    // Create an empty linked list
>    t_list *head = NULL;
>
>    // Add nodes to the list
>    int data1 = 42;
>    t_list *node1 = malloc(sizeof(t_list));
>    node1->content = &data1;
>    node1->next = NULL;
>
>    int data2 = 17;
>    t_list *node2 = malloc(sizeof(t_list));
>    node2->content = &data2;
>    node2->next = NULL;
>
>    // Add the nodes to the end of the list
>    ft_lstadd_back(&head, node1);
>    ft_lstadd_back(&head, node2);
>
>    // Print the contents of the linked list
>    t_list *current = head;
>    while (current != NULL)
>    {
>        int *content_ptr = (int *)(current->content);
>        printf("%d\n", *content_ptr);
>        current = current->next;
>    }
>
>    // Free memory allocated for the nodes
>    free(node1);
>    free(node2);
>
>    return (0);
>}
>```

## [ft_lstdelone](../libft/ft_lstdelone.c)

The `ft_lstdelone` function is used to delete (remove and deallocate memory for) a single node in a singly-linked list. It takes two arguments:

1. `t_list *lst`: A pointer to the node that you want to delete.

2. `void (*del)(void*)`: A pointer to a function responsible for deallocating the content of the node. The function takes a `void*` pointer as its argument, which typically points to the content of the node. This function is responsible for freeing any memory associated with the content of the node.

Here's a breakdown of how the `ft_lstdelone` function works:

- It first checks if the `del` function pointer is not `NULL`. This check ensures that the function pointer is valid and not a null pointer.

- Next, it checks if the `lst` pointer is not `NULL`. This check ensures that the node to be deleted exists in the list.

- If both conditions are met (i.e., `del` is valid and `lst` is not `NULL`), the function calls the `del` function, passing the `lst->content` pointer as its argument. This allows the `del` function to deallocate any memory associated with the content of the node.

- After deallocating the content, it frees the memory allocated for the `lst` node itself using the `free` function. This effectively removes the node from the linked list.

- If either the `del` function pointer is `NULL` or the `lst` pointer is `NULL`, the function simply returns without performing any deletion.

> [!INFO]
> Here's an example of how you might use the `ft_lstdelone` function, it's used to delete a node in a linked list. The `custom_del` function is provided to handle the deallocation of the content of the node, which is an integer in this case. After deletion, the program verifies whether the node has been deleted.:
> 
>```c
>// Definition of the del function here...
>void custom_del(void *content)
>{
>    // Custom deallocation logic for the content
>    free(content);
>}
>
>int main()
>{
>    // Create a node with some content
>    int *data = malloc(sizeof(int));
>    *data = 42;
>
>    t_list *node = malloc(sizeof(t_list));
>    node->content = data;
>    node->next = NULL;
>
>    // Delete the node using ft_lstdelone
>    ft_lstdelone(node, custom_del);
>
>    // Verify that the node has been deleted
>    if (node)
>        printf("Node still exists.\n");
>    else
>        printf("Node has been deleted.\n");
>
>    return 0;
>}
>```

## [ft_lstclear](../libft/ft_lstclear.c)

The `ft_lstclear` function is used to clear (delete and deallocate memory for) an entire singly-linked list. It takes two arguments:

1. `t_list **lst`: A pointer to a pointer to the head of the linked list. The double pointer `**lst` is used to modify the original pointer to the head of the list, ensuring that the head pointer is updated correctly after clearing the list.

2. `void (*del)(void*)`: A pointer to a function responsible for deallocating the content of each node in the list. The function takes a `void*` pointer as its argument, which typically points to the content of the node. This function is called for each node in the list to free any memory associated with the content.

Here's a breakdown of how the `ft_lstclear` function works:

- It first checks if the `del` function pointer is not `NULL`, if the `lst` pointer is not `NULL`, and if the `*lst` pointer is not `NULL`. These checks ensure that the function pointer is valid, that a list exists (i.e., `lst` is not `NULL`), and that the list is not empty (i.e., `*lst` is not `NULL`).

- Inside the loop, it uses a temporary pointer `temp` to store a pointer to the next node (`(*lst)->next`) before deleting the current node using the `ft_lstdelone` function. This ensures that the next node is not lost when the current node is deleted.

- After deleting the current node and updating the `temp` pointer, it sets the `*lst` pointer to the value of `temp`. This effectively moves the `*lst` pointer to the next node in the list, allowing the loop to continue.

- The loop continues until either the `lst` pointer becomes `NULL` (indicating that the end of the list has been reached) or the `*lst` pointer becomes `NULL` (indicating that the list is empty).

- If any of the initial conditions are not met (i.e., if `del` is `NULL`, `lst` is `NULL`, or `*lst` is `NULL`), the function returns without performing any deletion.

> [!INFO]
> Here's an example of how you might use the `ft_lstclear` function, it's used to clear (delete and deallocate memory for) a linked list with three nodes. The `custom_del` function is provided to handle the deallocation of the content of each node. After clearing the list, the program verifies whether the list is empty.:
>
>```c
>int main()
>{
>    // Create a linked list with three nodes
>    t_list *head = NULL;
>
>    // Add nodes to the list
>    int *data1 = malloc(sizeof(int));
>    *data1 = 42;
>    t_list *node1 = malloc(sizeof(t_list));
>    node1->content = data1;
>    node1->next = NULL;
>
>    int *data2 = malloc(sizeof(int));
>    *data2 = 17;
>    t_list *node2 = malloc(sizeof(t_list));
>    node2->content = data2;
>    node2->next = NULL;
>
>    int *data3 = malloc(sizeof(int));
>    *data3 = 99;
>    t_list *node3 = malloc(sizeof(t_list));
>    node3->content = data3;
>    node3->next = NULL;
>
>    // Link the nodes together
>    head = node1;
>    node1->next = node2;
>    node2->next = node3;
>
>    // Clear the linked list
>    ft_lstclear(&head, custom_del);
>
>    // Verify that the linked list is empty
>    if (head)
>        printf("Linked list is not empty.\n");
>    else
>        printf("Linked list has been cleared.\n");
>
>    return (0);
>}
>```

## [ft_lstiter](../libft/ft_lstiter.c)

The `ft_lstiter` function is used to apply a given function `f` to the content of each node in a singly-linked list. It takes two arguments:

1. `t_list *lst`: A pointer to the head of the linked list. This pointer is used to traverse the list from the beginning.

2. `void (*f)(void*)`: A pointer to a function that will be applied to the content of each node in the list. This function takes a `void*` pointer as its argument, which typically points to the content of the node. `f` is applied to each node's content in the order in which they appear in the list.

Here's a breakdown of how the `ft_lstiter` function works:

- It first checks if the function pointer `f` is not `NULL`. This check ensures that the function pointer is valid and not a null pointer.

- It then enters a loop that traverses the linked list from the head (`lst`) to the end of the list.

- Inside the loop, it calls the function `f` and passes the `lst->content` pointer as its argument. This effectively applies the function `f` to the content of the current node.

- After applying the function to the current node's content, it moves to the next node in the list by updating the `lst` pointer to `lst->next`. This allows it to process the next node in the list during the next iteration of the loop.

- The loop continues until it reaches the end of the list, at which point the `lst` pointer becomes `NULL`, and the loop terminates.

- If the `f` function pointer is `NULL`, the function returns without performing any iteration or function application.

> [!INFO]
>Here's an example of how you might use the `ft_lstiter` function, it's used to apply the `custom_function` to the content of each node in a linked list. The program then prints the values contained in each node's content.:
>
>```c
>// Definition of custom_function here...
>void custom_function(void *content)
>{
>    int *data = (int *)content;
>    printf("Value: %d\n", *data);
>}
>
>int main()
>{
>    // Create a linked list with three nodes
>    t_list *head = NULL;
>
>    // Add nodes to the list
>    int *data1 = malloc(sizeof(int));
>    *data1 = 42;
>    t_list *node1 = malloc(sizeof(t_list));
>    node1->content = data1;
>    node1->next = NULL;
>
>    int *data2 = malloc(sizeof(int));
>    *data2 = 17;
>    t_list *node2 = malloc(sizeof(t_list));
>    node2->content = data2;
>    node2->next = NULL;
>
>    int *data3 = malloc(sizeof(int));
>    *data3 = 99;
>    t_list *node3 = malloc(sizeof(t_list));
>    node3->content = data3;
>    node3->next = NULL;
>
>    // Link the nodes together
>    head = node1;
>    node1->next = node2;
>    node2->next = node3;
>
>    // Apply custom_function to the content of each node
>    ft_lstiter(head, custom_function);
>
>    // Free memory allocated for the nodes
>    free(node1);
>    free(node2);
>    free(node3);
>
>    return (0);
>}
>```

## [ft_lstmap](../libft/ft_lstmap.c)

The `ft_lstmap` function is used to create a new linked list by applying a function `f` to each element of the original linked list `lst`. It also takes an additional function `del` to handle the deallocation of any resources if an error occurs during the process. Here's a breakdown of how the `ft_lstmap` function works:

- It first checks if both the `f` and `del` function pointers are not `NULL`. This check ensures that both the mapping function and the cleanup function are valid and not null pointers.

- It initializes a new linked list `new_list` and sets it to `NULL`. This list will store the mapped elements from the original list.

- It enters a loop that traverses the original linked list `lst` from beginning to end.

- Inside the loop, it applies the function `f` to the content of the current node using `(*f)(lst->content)`. This function returns a new element that will be added to the new linked list.

- It creates a new node `new_node` using the `ft_lstnew` function and passes the mapped data as the content of the new node. If the creation of the new node fails (returns `NULL`), it proceeds to free the newly created list `new_list` and its data using `ft_lstclear`, ensuring that no memory leaks occur. Then it returns `NULL` to indicate the error.

- It adds the newly created `new_node` to the end of the `new_list` using `ft_lstadd_back`.

- It advances the `lst` pointer to the next node in the original list, continuing the iteration.

- The loop continues until it reaches the end of the original list, at which point the `lst` pointer becomes `NULL`, and the loop terminates.

- Finally, it returns the `new_list`, which contains the mapped elements from the original list.

The purpose of the `del` function is to handle the deallocation of any resources (e.g., memory) associated with the mapped elements if an error occurs during the process. It ensures that the memory is properly freed to prevent memory leaks.

> [!INFO]
> Here's an example of how you might use the `ft_lstmap` function, it's used to apply the `custom_mapping_function` to each element in the original linked list, creating a new linked list with the mapped elements. The `custom_del` function is used for cleanup. Finally, the program prints the mapped elements and frees the memory allocated for both the original and new linked lists:
>
>```c
>// Definitions of custom_mapping_function and custom_del functions here...
>
>void *custom_mapping_function(void *content)
>{
>    int *data = (int *)content;
>    // Perform some mapping operation here (e.g., doubling the integer value)
>    int *mapped_data = malloc(sizeof(int));
>    *mapped_data = 2 * (*data);
>    return (void *)mapped_data;
>}
>
>void custom_del(void *content)
>{
>    // Custom cleanup logic here (e.g., freeing allocated memory)
>    free(content);
>}
>
>int main()
>{
>    // Create a linked list with three nodes
>    t_list *head = NULL;
>
>    // Add nodes to the list
>    int *data1 = malloc(sizeof(int));
>    *data1 = 5;
>    t_list *node1 = malloc(sizeof(t_list));
>    node1->content = data1;
>    node1->next = NULL;
>
>    int *data2 = malloc(sizeof(int));
>    *data2 = 10;
>    t_list *node2 = malloc(sizeof(t_list));
>    node2->content = data2;
>    node2->next = NULL;
>
>    int *data3 = malloc(sizeof(int));
>    *data3 = 15;
>    t_list *node3 = malloc(sizeof(t_list));
>    node3->content = data3;
>    node3->next = NULL;
>
>    // Link the nodes together
>    head = node1;
>    node1->next = node2;
>    node2->next = node3;
>
>    // Map the elements using custom_mapping_function
>    t_list *new_list = ft_lstmap(head, custom_mapping_function, custom_del);
>
>    // Print the mapped elements
>    t_list *current = new_list;
>    while (current)
>    {
>        int *mapped_data = (int *)(current->content);
>        printf("Mapped Value: %d\n", *mapped_data);
>        current = current->next;
>    }
>
>    // Free memory allocated for the original list and mapped elements
>    ft_lstclear(&head, custom_del);
>    ft_lstclear(&new_list, custom_del);
>
>    return (0);
>}
>```