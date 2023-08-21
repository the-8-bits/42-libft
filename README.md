---
title: lib_ft
tags: 42, CommonCore, programação
use: README, Documentation
languages: C
dependences: NULL
---

>  Copied directly from [`42Porto`](https://www.42porto.com/) all rights reserved </br> If you spot somethig that isn't right, please open an [Issue](https://github.com/the-8-bits/42-libft/issues/new)

</br>
</br>


<p align="center">
  <picture>
    <img alt="List_logo" src="https://drive.google.com/uc?export=view&id=1rFqWh4miOnHABWGa2X7KTe2geXDhuD2S">
  </picture>
</p>

# <p align="center">**Libft**</p>
<p align="center">Your very first own library</p>
</br>
<p align="center"> <i>Summary:</br>
      This project is about coding a C library.</br>
      It will contain a lot of general purpose functions your programs will rely upon.</br>
      Version: 15</i></br>
</p>

</br>

---

</br>

<details><summary>Table of Contents 🔖</summary>

- [**Libft**](#libft)
- [**Chapter I**](#chapter-i)
	- [**Introduction**](#introduction)
- [**Chapter II**](#chapter-ii)
	- [**Common Instructions**](#common-instructions)
- [**Chapter III**](#chapter-iii)
	- [**Mandatory part**](#mandatory-part)
	- [**Technical considerations**](#technical-considerations)
	- [**Part 1 - Libc functions**](#part-1---libc-functions)
	- [**Part 2 - Additional functions**](#part-2---additional-functions)
- [**Chapter IV**](#chapter-iv)
	- [**Bonus part**](#bonus-part)
- [**Chapter V**](#chapter-v)
	- [**Submission and peer-evaluation**](#submission-and-peer-evaluation)

</details>

</br>

# **Chapter I**
## <a name="introduction"></a><a name="_bookmark0"></a>**Introduction**
C programming can be very tedious when one doesn’t have access to the highly useful standard functions. This project is about understanding the way these functions work, implementing and learning to use them. Your will create your own library. It will be helpful since you will use it in your next C school assignments.

Take the time to expand your libft throughout the year. However, when working on a new project, don’t forget to ensure the functions used in your library are allowed in the project guidelines.

# **Chapter II**
## <a name="common_instructions"></a><a name="_bookmark1"></a>**Common Instructions**

- Your project must be written in C.

Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.

Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.

All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.

If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags `-Wall -Wextra -Werror`, use `cc`, and your Makefile must not relink.

Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h} if the subject does not specify anything else. Mandatory and bonus part evaluation is done separately.

If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.

We encourage you to create test programs for your project even though this work **won’t have to be submitted and won’t be graded**. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.

Submit your work to your assigned git repository. Only the work in the git reposi- tory will be graded. If Deepthought is assigned to grade your work, it will be done


after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

# **Chapter III**
## <a name="mandatory_part"></a><a name="_bookmark2"></a>**Mandatory part**

| **Program name**     | libft.a                                                                                                    |
|:-------------------- |:---------------------------------------------------------------------------------------------------------- |
| **Turn in files**    | Makefile, libft.h, ft\_\*.c                                                                                |
| **Makefile**         | NAME, all, clean, fclean, re                                                                               |
| **External functs.** | Detailed below                                                                                             |
| **Libft authorized** | n/a                                                                                                        |
| **Description**      | <p>Write your own library: a collection of functions</p><p>that will be a useful tool for your cursus.</p> |


## <a name="technical_considerations"></a><a name="_bookmark3"></a>**Technical considerations**
   0. Declaring global variables is forbidden.

If you need helper functions to split a more complex function, define them as static functions. This way, their scope will be limited to the appropriate file.

0. Place all your files at the root of your repository.
0. Turning in unused files is forbidden.
0. Every .c files must compile with the flags -Wall -Wextra -Werror.

You must use the command ar to create your library. Using the libtool command is forbidden.

0. Your libft.a has to be created at the root of your repository.


## <a name="part_1_-_libc_functions"></a><a name="_bookmark4"></a>**Part 1 - Libc functions**
To begin, you must redo a set of functions from the libc. Your functions will have the same prototypes and implement the same behaviors as the originals. They must comply with the way they are defined in their man. The only difference will be their names. They will begin with the ’ft\_’ prefix. For instance, strlen becomes ft\_strlen.

<p align="center">
  <picture>
    <img alt="List_logo" src="https://drive.google.com/uc?export=view&id=1EYoFLHu3adL9iYt72AAGCngq38ZoOpx8">
  </picture>
</p>

You must write your own function implementing the following original ones. They do not require any external functions:

| ft_*    | done |
| ------- | ---- |
| isalpha | ✅   |
| isdigit | ✅   |
| isalnum | ✅   |
| isascii | :x:  |
| isprint | ✅   |
| strlen  | ✅   |
| memset  | :x:  |
| bzero   | :x:  |
| memcpy  | :x:  |
| memmove | :x:  |
| strlcpy | ✅   |
| strlcat | ✅   |
| toupper | ✅   |
| tolower | ✅   |
| strchr  | :x:  |
| strrchr | :x:  |
| strncmp | ✅   |
| memchr  | :x:  |
| memcmp  | :x:  |
| strnstr | :x:  |
| atoi    | ✅   |


In order to implement the two following functions, you will use malloc():

1. calloc
2. strdup

## <a name="part_2_-_additional_functions"></a><a name="_bookmark5"></a>**Part 2 - Additional functions**
In this second part, you must develop a set of functions that are either not in the libc, or that are part of it but in a different form.

| ft_*       | #   |
| ---------- | --- |
| substr     | :x: |
| strjoin    | :x: |
| strtrim    | :x: |
| split      | :x: |
| itoa       | :x: |
| strmapi    | :x: |
| striteri   | :x: |
| putchar_fd | :x: |
| putstr_fd  | :x: |
| putendl_fd | :x: |
| putnbr_fd  | :x: |

<p align="center">
  <picture>
    <img alt="List_logo" src="https://drive.google.com/uc?export=view&id=1XJwpDnluZXtoXKvrlci70FZHNARCqKKP">
  </picture>
</p>

<details>
	<summary> ft_substr </summary>

| **Function name**    | ft\_substr                                                                                                                                                                |
|:-------------------- |:------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | <p>char \*ft\_substr(char const \*s, unsigned int start,</p><p>size\_t len);</p>                                                                                          |
| **Turn in files**    | -                                                                                                                                                                         |
| **Parameters**       | <p>s: The string from which to create the substring.</p><p>start: The start index of the substring in the string ’s’.</p><p>len: The maximum length of the substring.</p> |
| **Return value**     | <p>The substring.</p><p>NULL if the allocation fails.</p>                                                                                                                 |
| **External functs.** | malloc                                                                                                                                                                    |
| **Description**      | <p>Allocates (with malloc(3)) and returns a substring</p><p>from the string ’s’.</p><p>The substring begins at index ’start’ and is of maximum size ’len’.</p>            |

</details>


<details>
	<summary> ft_strjoin </summary>

| **Function name**    | ft\_strjoin                                                                                                                  |
|:-------------------- |:---------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | char \*ft\_strjoin(char const \*s1, char const \*s2);                                                                        |
| **Turn in files**    | -                                                                                                                            |
| **Parameters**       | <p>s1: The prefix string.</p><p>s2: The suffix string.</p>                                                                   |
| **Return value**     | <p>The new string.</p><p>NULL if the allocation fails.</p>                                                                   |
| **External functs.** | malloc                                                                                                                       |
| **Description**      | <p>Allocates (with malloc(3)) and returns a new</p><p>string, which is the result of the concatenation of ’s1’ and ’s2’.</p> |

</details>

<details>
	<summary> ft_strtrim </summary>

| **Function name**    | ft\_strtrim                                                                                                                                                     |
|:-------------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | char \*ft\_strtrim(char const \*s1, char const \*set);                                                                                                          |
| **Turn in files**    | -                                                                                                                                                               |
| **Parameters**       | <p>s1: The string to be trimmed.</p><p>set: The reference set of characters to trim.</p>                                                                        |
| **Return value**     | <p>The trimmed string.</p><p>NULL if the allocation fails.</p>                                                                                                  |
| **External functs.** | malloc                                                                                                                                                          |
| **Description**      | <p>Allocates (with malloc(3)) and returns a copy of</p><p>’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.</p> |

</details>

<details>
	<summary> ft_split </summary>
  
| **Function name**    | ft\_split                                                                                                                                                                         |
|:-------------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | char \*\*ft\_split(char const \*s, char c);                                                                                                                                       |
| **Turn in files**    | -                                                                                                                                                                                 |
| **Parameters**       | <p>s: The string to be split.</p><p>c: The delimiter character.</p>                                                                                                               |
| **Return value**     | <p>The array of new strings resulting from the split.</p><p>NULL if the allocation fails.</p>                                                                                     |
| **External functs.** | malloc, free                                                                                                                                                                      |
| **Description**      | <p>Allocates (with malloc(3)) and returns an array</p><p>of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must end with a NULL pointer.</p> |

</details>

<details>
	<summary> ft_itoa </summary>

| **Function name**    | ft\_itoa                                                                                                                                         |
|:-------------------- |:------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Prototype**        | char \*ft\_itoa(int n);                                                                                                                          |
| **Turn in files**    | -                                                                                                                                                |
| **Parameters**       | n: the integer to convert.                                                                                                                       |
| **Return value**     | <p>The string representing the integer.</p><p>NULL if the allocation fails.</p>                                                                  |
| **External functs.** | malloc                                                                                                                                           |
| **Description**      | <p>Allocates (with malloc(3)) and returns a string</p><p>representing the integer received as an argument. Negative numbers must be handled.</p> |

</details>

<details>
	<summary> ft_strmapi </summary>

| **Function name**    | ft\_strmapi                                                                                                                                                                                               |
|:-------------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | <p>char \*ft\_strmapi(char const \*s, char (\*f)(unsigned</p><p>int, char));</p>                                                                                                                          |
| **Turn in files**    | -                                                                                                                                                                                                         |
| **Parameters**       | <p>s: The string on which to iterate.</p><p>f: The function to apply to each character.</p>                                                                                                               |
| **Return value**     | <p>The string created from the successive applications</p><p>of ’f’.</p><p>Returns NULL if the allocation fails.</p>                                                                                      |
| **External functs.** | malloc                                                                                                                                                                                                    |
| **Description**      | <p>Applies the function ’f’ to each character of the</p><p>string ’s’, and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.</p> |

</details>

<details>
	<summary> ft_striteri </summary>

| **Function name**    | ft\_striteri                                                                                                                                                                                           |
|:-------------------- |:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Prototype**        | <p>void ft\_striteri(char \*s, void (\*f)(unsigned int,</p><p>char\*));</p>                                                                                                                            |
| **Turn in files**    | -                                                                                                                                                                                                      |
| **Parameters**       | <p>s: The string on which to iterate.</p><p>f: The function to apply to each character.</p>                                                                                                            |
| **Return value**     | None                                                                                                                                                                                                   |
| **External functs.** | None                                                                                                                                                                                                   |
| **Description**      | <p>Applies the function ’f’ on each character of</p><p>the string passed as argument, passing its index as first argument. Each character is passed by address to ’f’ to be modified if necessary.</p> |

</details>

<details>
	<summary> ft_putchar </summary>

| **Function name**    | ft\_putchar\_fd                                                                     |
|:-------------------- |:----------------------------------------------------------------------------------- |
| **Prototype**        | void ft\_putchar\_fd(char c, int fd);                                               |
| **Turn in files**    | -                                                                                   |
| **Parameters**       | <p>c: The character to output.</p><p>fd: The file descriptor on which to write.</p> |
| **Return value**     | None                                                                                |
| **External functs.** | write                                                                               |
| **Description**      | <p>Outputs the character ’c’ to the given file</p><p>descriptor.</p>                |

</details>

<details>
	<summary> ft_putstr </summary>

| **Function name**    | ft\_putstr\_fd                                                                   |
|:-------------------- |:-------------------------------------------------------------------------------- |
| **Prototype**        | void ft\_putstr\_fd(char \*s, int fd);                                           |
| **Turn in files**    | -                                                                                |
| **Parameters**       | <p>s: The string to output.</p><p>fd: The file descriptor on which to write.</p> |
| **Return value**     | None                                                                             |
| **External functs.** | write                                                                            |
| **Description**      | <p>Outputs the string ’s’ to the given file</p><p>descriptor.</p>                |

</details>

<details>
	<summary> ft_putendl </summary>

| **Function name**    | ft\_putendl\_fd                                                                         |
|:-------------------- |:--------------------------------------------------------------------------------------- |
| **Prototype**        | void ft\_putendl\_fd(char \*s, int fd);                                                 |
| **Turn in files**    | -                                                                                       |
| **Parameters**       | <p>s: The string to output.</p><p>fd: The file descriptor on which to write.</p>        |
| **Return value**     | None                                                                                    |
| **External functs.** | write                                                                                   |
| **Description**      | <p>Outputs the string ’s’ to the given file descriptor</p><p>followed by a newline.</p> |

</details>

<details>
	<summary> ft_putnbr </summary>

| **Function name**    | ft\_putnbr\_fd                                                                    |
|:-------------------- |:--------------------------------------------------------------------------------- |
| **Prototype**        | void ft\_putnbr\_fd(int n, int fd);                                               |
| **Turn in files**    | -                                                                                 |
| **Parameters**       | <p>n: The integer to output.</p><p>fd: The file descriptor on which to write.</p> |
| **Return value**     | None                                                                              |
| **External functs.** | write                                                                             |
| **Description**      | <p>Outputs the integer ’n’ to the given file</p><p>descriptor.</p>                |

</details>
</br>

# **Chapter IV**
## <a name="bonus_part"></a><a name="_bookmark6"></a>**Bonus part**
If you completed the mandatory part, do not hesitate to go further by doing this extra one. It will bring bonus points if passed successfully.

Functions to manipulate memory and strings is very useful. But you will soon discover that manipulating lists is even more useful.

You have to use the following structure to represent a node of your list. Add its declaration to your libft.h file:

```c
typedef struct	s_list
{
void	*content;
struct s_list	*next;
}	t_list;
```

The members of the t\_list struct are:

- content: The data contained in the node.

> `void *` allows to store any kind of data.

- next: The address of the next node, or NULL if the next node is the last one.

In your Makefile, add a make bonus rule to add the bonus functions to your libft.a.

<p align="center">
  <picture>
    <img alt="List_logo" src="https://drive.google.com/uc?export=view&id=1UnkJN-meo9OUDrzDc7R6s6sk8eicvfp-">
  </picture>
</p>

Implement the following functions in order to easily use your lists.

<details>
	<summary> ft_lstnew </summary>

| **Function name**    | ft\_lstnew                                                                                                                                                                                          |
|:-------------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | t\_list \*ft\_lstnew(void \*content);                                                                                                                                                               |
| **Turn in files**    | -                                                                                                                                                                                                   |
| **Parameters**       | content: The content to create the node with.                                                                                                                                                       |
| **Return value**     | The new node                                                                                                                                                                                        |
| **External functs.** | malloc                                                                                                                                                                                              |
| **Description**      | <p>Allocates (with malloc(3)) and returns a new node.</p><p>The member variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.</p> |

</details>

<details>
	<summary> ft_lstadd </summary>

| **Function name**    | ft\_lstadd\_front                                                                                                                                |
|:-------------------- |:------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Prototype**        | void ft\_lstadd\_front(t\_list \*\*lst, t\_list \*new);                                                                                          |
| **Turn in files**    | -                                                                                                                                                |
| **Parameters**       | <p>lst: The address of a pointer to the first link of</p><p>a list.</p><p>new: The address of a pointer to the node to be added to the list.</p> |
| **Return value**     | None                                                                                                                                             |
| **External functs.** | None                                                                                                                                             |
| **Description**      | Adds the node ’new’ at the beginning of the list.                                                                                                |

</details>

<details>
	<summary> ft_lstsize </summary>

| **Function name**    | ft\_lstsize                           |
|:-------------------- |:------------------------------------- |
| **Prototype**        | int ft\_lstsize(t\_list \*lst);       |
| **Turn in files**    | -                                     |
| **Parameters**       | lst: The beginning of the list.       |
| **Return value**     | The length of the list                |
| **External functs.** | None                                  |
| **Description**      | Counts the number of nodes in a list. |

</details>

<details>
	<summary> ft_lstlast </summary>

| **Function name**    | ft\_lstlast                           |
|:-------------------- |:------------------------------------- |
| **Prototype**        | t\_list \*ft\_lstlast(t\_list \*lst); |
| **Turn in files**    | -                                     |
| **Parameters**       | lst: The beginning of the list.       |
| **Return value**     | Last node of the list                 |
| **External functs.** | None                                  |
| **Description**      | Returns the last node of the list.    |

</details>

<details>
	<summary> ft_lstadd </summary>

| **Function name**    | ft\_lstadd\_back                                                                                                                                 |
|:-------------------- |:------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Prototype**        | void ft\_lstadd\_back(t\_list \*\*lst, t\_list \*new);                                                                                           |
| **Turn in files**    | -                                                                                                                                                |
| **Parameters**       | <p>lst: The address of a pointer to the first link of</p><p>a list.</p><p>new: The address of a pointer to the node to be added to the list.</p> |
| **Return value**     | None                                                                                                                                             |
| **External functs.** | None                                                                                                                                             |
| **Description**      | Adds the node ’new’ at the end of the list.                                                                                                      |

</details>

<details>
	<summary> ft_lstdelone </summary>

| **Function name**    | ft\_lstdelone                                                                                                                                                                                |
|:-------------------- |:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | <p>void ft\_lstdelone(t\_list \*lst, void (\*del)(void</p><p>\*));</p>                                                                                                                       |
| **Turn in files**    | -                                                                                                                                                                                            |
| **Parameters**       | <p>lst: The node to free.</p><p>del: The address of the function used to delete the content.</p>                                                                                             |
| **Return value**     | None                                                                                                                                                                                         |
| **External functs.** | free                                                                                                                                                                                         |
| **Description**      | <p>Takes as a parameter a node and frees the memory of</p><p>the node’s content using the function ’del’ given as a parameter and free the node. The memory of ’next’ must not be freed.</p> |

</details>

<details>
	<summary> ft_lstclear </summary>

| **Function name**    | ft\_lstclear                                                                                                                                                                      |
|:-------------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | <p>void ft\_lstclear(t\_list \*\*lst, void (\*del)(void</p><p>\*));</p>                                                                                                           |
| **Turn in files**    | -                                                                                                                                                                                 |
| **Parameters**       | <p>lst: The address of a pointer to a node.</p><p>del: The address of the function used to delete the content of the node.</p>                                                    |
| **Return value**     | None                                                                                                                                                                              |
| **External functs.** | free                                                                                                                                                                              |
| **Description**      | <p>Deletes and frees the given node and every</p><p>successor of that node, using the function ’del’ and free(3).</p><p>Finally, the pointer to the list must be set to NULL.</p> |

</details>

<details>
	<summary> ft_lstiter </summary>
  
| **Function name**    | ft\_lstiter                                                                                                       |
|:-------------------- |:----------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | void ft\_lstiter(t\_list \*lst, void (\*f)(void \*));                                                             |
| **Turn in files**    | -                                                                                                                 |
| **Parameters**       | <p>lst: The address of a pointer to a node.</p><p>f: The address of the function used to iterate on the list.</p> |
| **Return value**     | None                                                                                                              |
| **External functs.** | None                                                                                                              |
| **Description**      | <p>Iterates the list ’lst’ and applies the function</p><p>’f’ on the content of each node.</p>                    |

</details>

<details>
	<summary> ft_lstmap </summary>

| **Function name**    | ft\_lstmap                                                                                                                                                                                                                                            |
|:-------------------- |:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**        | <p>t\_list \*ft\_lstmap(t\_list \*lst, void \*(\*f)(void \*),</p><p>void (\*del)(void \*));</p>                                                                                                                                                       |
| **Turn in files**    | -                                                                                                                                                                                                                                                     |
| **Parameters**       | <p>lst: The address of a pointer to a node.</p><p>f: The address of the function used to iterate on the list.</p><p>del: The address of the function used to delete the content of a node if needed.</p>                                              |
| **Return value**     | <p>The new list.</p><p>NULL if the allocation fails.</p>                                                                                                                                                                                              |
| **External functs.** | malloc, free                                                                                                                                                                                                                                          |
| **Description**      | <p>Iterates the list ’lst’ and applies the function</p><p>’f’ on the content of each node. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed.</p> |

</details>
</br>

# **Chapter V**
## <a name="submission_and_peer-evaluation"></a><a name="_bookmark7"></a>**Submission and peer-evaluation**

Turn in your assignment in your Git repository as usual. Only the work inside your repos- itory will be evaluated during the defense. Don’t hesitate to double check the names of your files to ensure they are correct.

Place all your files at the root of your repository.
