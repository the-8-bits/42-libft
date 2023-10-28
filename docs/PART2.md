---
title: Libft - Part 2
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

- [Part 2 #to\_review](#part-2-to_review)
  - [ft\_substr](#ft_substr)
  - [ft\_strjoin](#ft_strjoin)
  - [ft\_strtrim](#ft_strtrim)
  - [ft\_split](#ft_split)
  - [ft\_itoa](#ft_itoa)
  - [ft\_strmapi](#ft_strmapi)
  - [ft\_striteri](#ft_striteri)
  - [ft\_putchar\_fd](#ft_putchar_fd)
  - [ft\_putstr\_fd](#ft_putstr_fd)
  - [ft\_putendl\_fd](#ft_putendl_fd)
  - [ft\_putnbr\_fd](#ft_putnbr_fd)

---

# Part 2 #to_review

## [ft_substr](../libft/ft_substr.c)

The `ft_substr` function is designed to extract a substring from a given string `s` starting from a specified index `start` and of a specified length `len`. It allocates memory for the substring and returns a pointer to it.

Usage Context:
- `ft_substr` is typically used when you want to extract a portion of a larger string, such as extracting a substring from a text message or extracting part of a filename.

Key Points:
- `char const *s`: A pointer to the input string from which the substring will be extracted.
- `unsigned int start`: The index from which the substring extraction should begin.
- `size_t len`: The maximum length of the extracted substring.

How it Works:
- The function first calculates the length of the input string `s` using the `ft_strlen` function and stores it in `s_len`.

- It checks if the `start` index is greater than or equal to `s_len`, which would mean that the starting index is beyond the end of the input string. In this case, it returns an empty string (a string containing only a null terminator) to indicate that there's nothing to extract.

- It then adjusts the `len` value to ensure that it doesn't exceed the number of available characters in the string `s`. If `len` is greater than the remaining characters in `s` starting from the `start` index, it sets `len` to the available characters.

- The function allocates memory for the substring plus a null terminator using `malloc`. It checks if the allocation was successful. If not, it returns `NULL` to indicate a memory allocation failure.

- It uses `memcpy` to copy the substring from the input string `s` starting from the `start` index and spanning `len` characters into the newly allocated memory `str`.

- Finally, it null-terminates the `str` to ensure it's a valid C string.

- The function returns a pointer to the allocated and null-terminated substring.

In summary, `ft_substr` is a utility function for extracting substrings from input strings, taking into account the starting index and the desired length. It handles memory allocation and ensures that the extracted substring is null-terminated, making it a valid C string.

## [ft_strjoin](../libft/ft_strjoin.c)

> Changes: added `ft_memset` to initialize the memory allocated for the new string, which resulted in undefined behaviours. `ft_memset` sets the memory to zero before copying the strings.  
> `ft_memset` and `ft_bzero` are both functions that can be used to set a block of memory to a specific value. However, there is a key difference between the two functions.  
> `ft_memset` sets a block of memory to a specific value, whereas `ft_bzero` sets a block of memory to zero.  
> In the case of `ft_strjoin`, we need to set the memory to zero before copying the strings to avoid undefined behavior. Therefore, `ft_bzero` would be a good choice for this specific use case. However, `ft_memset` is a more general-purpose function that can be used to set a block of memory to any value, not just zero.  


Diferent from the Piscine code where `char	*ft_strjoin(int size, char **strs, char *sep)` had three args, now it has only two: The `ft_strjoin` function is designed to concatenate (join) two strings, `s1` and `s2`, into a new string and return a pointer to the newly created string. It allocates memory for the result and copies both input strings into it.

Usage Context:
- `ft_strjoin` is typically used when you want to combine (concatenate) two strings into a single string.

Key Points:
- `const char *s1`: A pointer to the first string to be concatenated.
- `const char *s2`: A pointer to the second string to be concatenated.

How it Works:
- The function begins by calculating the lengths of the input strings `s1` and `s2` using `ft_strlen`. The lengths are stored in `len1` and `len2`.

- It then allocates memory for the result string `str` using `malloc`. The size of the allocated memory is calculated as `len1 + len2 + 1`, where `1` is added for the null terminator. This ensures that the memory can hold both strings and is null-terminated.

- If memory allocation fails (when `malloc` returns `NULL`), the function returns `NULL` to indicate the failure.

- Next, the function uses `ft_strcat` (a custom concatenation function as described earlier) twice. First, it copies the characters from `s1` into `str`, effectively initializing `str` with the contents of `s1`. Then, it appends the characters from `s2` to the end of `str`, resulting in the concatenation of `s1` and `s2`.

- Finally, the function returns a pointer to the newly created concatenated string.

Here the updates made:

1. We define our own `ft_strcat` function to concatenate two strings. It calculates the lengths of `dest` and `src` using `ft_strlen`, then uses `memcpy` to copy `src` onto the end of `dest`, including the null terminator.

2. In the `ft_strjoin` function, we use `ft_strcat` to copy `s1` into `str`, and then we append `s2` to `str` using `ft_strcat` again.

## [ft_strtrim](../libft/ft_strtrim.c)

The `ft_strtrim` function is designed to create a new string by removing specified leading and trailing characters from the input string `s1`. It takes two arguments: the input string `s1` and a set of characters `set` that should be considered for removal. The resulting string is returned, and it is dynamically allocated.

Usage Context:
- `ft_strtrim` is typically used when you want to remove certain characters (specified in the `set` parameter) from the beginning and end of a string. This can be useful for cleaning up input strings, such as user input or file content.

Key Points:
- `const char *s1`: A pointer to the input string that you want to trim.
- `const char *set`: A pointer to a string containing characters to be considered for removal from `s1`.

How it Works:
- The function first checks if either `s1` or `set` is NULL. If either is NULL, it returns `NULL` to indicate an error condition.

  ```c
	if (!s1 || !set)
		return (NULL); // Return NULL if either s1 or set is NULL
  ```

- It initializes two variables, `start` and `end`, to 0 and the length of `s1` (obtained using `ft_strlen(s1)`), respectively. These variables will be used to determine the start and end positions of the trimmed string.

- The function then enters two while loops:
  - The first while loop (starting from the beginning of `s1`) increments `start` while the characters in `s1` match characters in the `set`. This effectively skips leading characters that should be removed.

  ```c
	// Find the start position by skipping characters in set from the beginning of s1
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
  ```
  
  - The second while loop (starting from the end of `s1`) decrements `end` while the characters in `s1` match characters in the `set`. This skips trailing characters that should be removed.
  
  ```c
	// Find the end position by skipping characters in set from the end of s1
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
  ```

- After finding the start and end positions of the trimmed string, the function calculates the length of the trimmed string (`trimmed_len`) by subtracting `start` from `end`.
- 
- It then allocates memory for the trimmed string plus a null terminator using `malloc`. If memory allocation fails, it returns `NULL`.
  
  ```c
	// Allocate memory for the trimmed string plus a null terminator
	char *str = (char *)malloc(trimmed_len + 1);
	
	if (!str)
		return (NULL); // Return NULL if memory allocation fails
  ```

- Using a `counter` variable, the function copies the trimmed characters from `s1` to the newly allocated `str`.

  ```c
	// Copy the trimmed characters from s1 to str
	counter = 0;
	while (start < end)
		str[counter++] = s1[start++];
	
	str[counter] = '\0'; // Null-terminate the trimmed string
	return (str); // Return a pointer to the trimmed string
  ```

- Finally, it null-terminates the `str` to ensure it's a valid C string and returns a pointer to the trimmed string.

## [ft_split](../libft/ft_split.c)

To achieve `ft_split` we need to use some helper functions:

Certainly! Let's break down the functionality of each function within the code:

1. `ft_count_words` Function:
   - This function counts the number of words in a given string `s` where words are separated by a specified character `c`.

	```c
	static size_t ft_count_words(const char *s, char c)
	{
	    size_t	count;
	    int		is_inside_word;
		
	    count = 0;
	    is_inside_word = 0;
	    while (*s)
	    {
		    if (*s == c)
		        is_inside_word = 0;
		    else if (!is_inside_word)
		    {
		        is_inside_word = 1;
		        count++;
		    }
		    s++;
	    }
	    return (count);
	}
	```

   - It uses a loop to check whether the character at `*s` is the delimiter character `c` or not. Depending on whether it is part of a word or not, it updates the `is_inside_word` flag and increments the `count` variable accordingly..
   - It keeps track of whether it is currently inside a word (meaning it has encountered non-`c` characters).
   - Whenever it encounters a non-`c` character and is not inside a word, it increments the `count` to indicate the start of a new word.
   - When it encounters a `c` character and is inside a word, it sets `is_inside_word` to `0` to mark the end of the current word.
   - The function returns the total count of words found in the string.

2. `ft_split` Function:
   - This function splits a given string `s` into an array of words based on the separator character `c`.

	```c
	char **ft_split(char const *s, char c)
	{
		char	**split; // Array of strings
	    size_t	split_index; // Index of the current string in the array
		
	    if (!s)
		    return (NULL);
	    split = (char **)malloc(sizeof(char *) * (h_count_words(s, c) + 1));
	    if (!split)
	      return (NULL);
	    split_index = 0;
	    while (*s)
	    {
	      if (*s != c)
	        h_actual_split(s, c, split, split_index)
	      else
	        s++;
	    }
	    split[split_index] = NULL;
	    return (split);
	}
	```

   - As required by 42 Norm, the variables are declared in the begening of the function.
   - Then it checks if the input string `s` is not NULL; if it is NULL, it returns NULL to indicate an error.
   - It calculates the number of words in the string `s` by calling the `h_count_words` function.
   - It allocates memory for an array of strings `split` to store the words. The size of the array is `num_words` + $1$ to account for the NULL pointer at the end.
   - Then starts a loop that iterates through the characters of the input string `s` until it reaches the null terminator, which marks the end of the string. Inside the loop:
     - `if (*s != c)`: This condition checks if the current character `*s` is not equal to the delimiter character `c`. If it's not, it means the current character is part of a word, and the `h_actual_split` function (not shown in the provided code) is called to split the string at this point and store the substring in the `split` array at the `split_index` position.
     - `else`: If the current character is the delimiter character `c`, it is skipped by incrementing the `s` pointer.

   - After the loop completes, `split[split_index] = NULL;` sets the last element of the `split` array to `NULL` to indicate the end of the array of strings.

3. `h_actual_split` helper function:
  - Is responsible for determining the length of the current word, creating a duplicate of that word, and storing it in the `split` array at the appropriate index. It also updates the `s` pointer to point to the next portion of the string to be processed. This function plays a crucial role in the overall behavior of the `ft_split` implementation for splitting a string into substrings based on a delimiter character.
  
  ```c
  void	h_actual_split(s, c, split, split_index)
  {
    size_t	word_length; // Length of the current word.
	
    word_length = 0;
    while (s[word_length] && s[word_length] != c)
      word_length++;
    split[split_index++] = ft_strndup(s, word_length);
    s += word_length;
  }
  ```

## [ft_itoa](../libft/ft_itoa.c)

The `ft_itoa` function is designed to convert an integer `n` into a string representation of that integer. It dynamically allocates memory for the resulting string, handles negative numbers, and reverses the digits to create the correct string representation.

Here's the function with an explanation of its purpose and usage:

```c
char *ft_itoa(int n)
{
    char *str;
    int is_negative;
    size_t length = 0;

    is_negative = (n < 0);

    if (!(str = (char *)malloc(12 + is_negative))) // Assuming int has 32 bits, so 12 characters max
        return (NULL);

    if (n == 0)
    {
        str[length++] = '0';
    }
    else
    {
        while (n != 0)
        {
            str[length++] = '0' + ft_abs(n % 10);
            n = n / 10;
        }
    }

    if (is_negative)
    {
        str[length++] = '-';
    }

    str[length] = '\0';
    ft_strrev(str); // Reverse the string to get the correct representation
    return (str);
}
```

Usage Context:
- `ft_itoa` is typically used when you need to convert an integer into a string, for example, when you want to display the integer as text or store it as part of a string.

Key Points:
- `int n`: The integer to be converted to a string.

How it Works:
- The function starts by determining if the input integer `n` is negative and sets the `is_negative` flag accordingly.

- It allocates memory for the resulting string `str`. The size of the allocated memory is determined based on the maximum possible length of the string representation of an integer (`12` characters) plus an extra character for the negative sign (if applicable).

- If `n` is `0`, the function adds the character `'0'` to the string and increments the `length` counter.

- If `n` is not `0`, the function enters a loop that iteratively extracts the last digit of `n`, converts it to a character, and adds it to the string. The loop continues until `n` becomes `0`. Here in more detail:
	- `str[length++] = '0' + ft_abs(n % 10);`:
		- `n % 10`: This expression calculates the remainder of `n` when divided by 10. This effectively gives you the last digit of the number `n`.
		- `ft_abs(...)`: This is a function (presumably) that calculates the absolute value of a number. It ensures that the digit is positive, even if `n` is negative.
		- `'0' + ...`: This part converts the digit (which is currently an integer) into its character representation. In C, you can do this by adding the integer value to the character '0'. This works because the ASCII values of digits are sequential, so adding the integer value to '0' gives you the character representation of the digit.
	
	   So, `str[length++]` assigns the character representation of the last digit to the `length`-th position in the `str` array, and then `length` is incremented to prepare for the next digit.
	
	- `n = n / 10;`: This line effectively removes the last digit from `n` by integer division by 10. This step is crucial because it processes the digits one by one from right to left. After this line, `n` will contain the remaining digits, and the loop will continue until `n` becomes zero.

- If `n` was originally negative, the function adds a `'-'` character to the string to indicate the negative sign.

- It null-terminates the string by setting `str[length]` to `'\0'`.

- Finally, the function calls `ft_strrev` to reverse the string, ensuring that the string representation of the integer is correctly ordered. For example, `123` becomes `'321'`.

- The function returns a pointer to the dynamically allocated string containing the integer's string representation.

## [ft_strmapi](../libft/ft_strmapi.c)

The `ft_strmapi` function is designed to apply a given function `f` to each character of a string `s` and create a new string with the modified characters. It allocates memory for the resulting string and returns a pointer to it.

Usage Context:
- `ft_strmapi` is used when you want to apply a custom function to each character of a string to modify or transform the characters individually. It's often used in string manipulation tasks where character-wise processing is required.

Key Points:
- `char const *s`: A pointer to the input string `s` that you want to process.
- `char (*f)(unsigned int, char)`: A function pointer to a custom function `f` that takes an unsigned integer index and a character as arguments and returns a character.

How it Works:
- The function begins by duplicating the input string `s` using `ft_strdup`. This ensures that the original string remains unchanged, and the modifications are applied to a new copy of the string `str`.

- It initializes a variable `idx` to 0, which will be used as the index to traverse the characters of the string.

- The function enters a loop that iterates through the characters of the string `str` (the duplicated string).

- Inside the loop, for each character at index `idx`, it calls the custom function `f` with two arguments: `idx` (the current index) and `str[idx]` (the current character). The result of the function call replaces the character in the string `str` at the same index.

    ```c
    while (str[idx])
    {
        str[idx] = (*f)(idx, str[idx]); // Apply the function 'f' to each character
        idx++;
    }
    ```

- The loop continues until the null terminator `'\0'` is encountered, indicating the end of the string.

- After processing all characters and applying the custom function to each of them, the function returns a pointer to the newly created string `str`.

## [ft_striteri](../libft/ft_striteri.c)

The `ft_striteri` function is designed to apply a given function `f` to each character of a string `s`, passing both the character and its index to the function. It allows for in-place modification of the characters in the string.

Here's the function with an explanation of its purpose and usage:

```c
void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    if (s != NULL && f != NULL)
    {
        unsigned int index = 0;

        while (*s)
        {
            (*f)(index, s); // Call the function 'f' with the current index and character
            s++; // Move to the next character
            index++; // Increment the index
        }
    }
}
```

Usage Context:
- `ft_striteri` is used when you want to apply a custom function to each character of a string and have access to both the character and its index. This can be useful for in-place modifications of the string.

Key Points:
- `char *s`: A pointer to the input string `s` that you want to process.
- `void (*f)(unsigned int, char *)`: A function pointer to a custom function `f` that takes an unsigned integer index and a character pointer as arguments.

How it Works:
- The function begins by checking if both the input string `s` and the custom function pointer `f` are not NULL. If either of them is NULL, the function returns without performing any action.

- It initializes an unsigned integer variable `index` to 0. This variable will be used to keep track of the index of the current character being processed.

- The function enters a loop that iterates through the characters of the string `s` using a pointer.

- Inside the loop, for each character, it calls the custom function `f` with two arguments: `index` (the current index) and a pointer to the current character `s`. This allows the custom function to access and potentially modify the character at the specified index.

    ```c
    while (*s)
    {
        (*f)(index, s); // Call the function 'f' with the current index and character
        s++; // Move to the next character
        index++; // Increment the index
    }
    ```

- After calling the custom function, the function increments the character pointer `s` to move to the next character and increments the `index` to keep track of the index of the next character.

- The loop continues until it reaches the null terminator `'\0'`, indicating the end of the string.

- If both the string and the custom function are valid (non-NULL), this function iterates through the entire string, applying the custom function to each character.

> [!INFO]
> There's a possibility to divide this function into two, using a helper function called `ft_apply_function`. We'll discuss the use of function pointers and placeholders.
> 
>**1. Function Pointer (`void (*f)(unsigned int, char *)`):**  
>   In your `ft_striteri` function, you are given a function pointer `f` as one of the parameters. This function pointer is expected to point to a function that takes two arguments: an `unsigned int` and a `char *`. The `unsigned int` represents the index of the character in the string, and the `char *` represents a pointer to the character itself.
> 
>**2. Helper Function (`ft_apply_function`):**  
>   The `ft_apply_function` is a helper function designed to apply the function pointed to by `f` to a character in the string. Here's how it works:
> 
>  - It takes three parameters:
>     - `index`: An `unsigned int` representing the index of the character in the string.
>     - `char_ptr`: A `char *` pointer to the character itself.
>     - `f`: A function pointer that specifies the function to apply.
> 
>   - Inside the `ft_apply_function`, it checks if `char_ptr` is not `NULL` to ensure that it's safe to apply the function.
>     ```c
>       if (!char_ptr)
>         return;
>     ```
> 
>   - Then, it calls the function pointed to by `f` with the `index` and `char_ptr` as arguments. This is where the actual processing of the character takes place based on the function pointed to by `f`.
>     ```c
>       (*f)(index, char_ptr);
>     ```
> 
>**3. Placeholder (`(*f)(index, s)`):**  
>   In the `ft_striteri` function, when you call `(*f)(index, s)`, you're using the function pointer `f` to call the function that will process the character pointed to by `s` at the given `index`. Here's how it works:
> 
>   - `index` is the index of the character in the string.
>   - `s` is a pointer to the character at that index.
> 
>   When you call `(*f)(index, s)`, you are essentially invoking the function pointed to by `f` and passing in the index and a pointer to the character as arguments. This allows you to apply any custom processing or operation to the character at that specific index.
> 
>**Why Use `ft_apply_function` as a Helper:**  
>   The use of `ft_apply_function` as a helper function abstracts away the details of calling the function pointed to by `f` and makes the code inside `ft_striteri` cleaner and more focused. It separates the logic of iterating through the string and applying the function from the actual processing of the character, enhancing code modularity and readability. It also makes the code more maintainable and allows for better code reuse in case similar operations are needed elsewhere in your codebase.
> 
>```c
>static void ft_apply_function(unsigned int index, char *char_ptr, void (*f)>(unsigned int, char *))
>{
>    if (!char_ptr)
>        return;
>
>    (*f)(index, char_ptr);
>}
>```


In my head was a bit of confusion between the two above, so here an explanation:

> `ft_strmapi` and `ft_striteri` are two functions used for manipulating strings. These functions are not part of the C standard library; instead, they are part of a custom library often used in educational or project-based settings, which is the case.

The main difference between `ft_strmapi` and `ft_striteri` is that `ft_strmapi` returns a new dynamically allocated string with the result of applying a user-defined function to each character in the input string while preserving the original string, whereas `ft_striteri` modifies the characters in the original string in place using a user-defined function. The choice between these functions depends on whether you want to create a new string or modify the original one.

1. `ft_strmapi`:

   - Prototype: `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`
   - Purpose: `ft_strmapi` stands for "string map with index." It takes a string `s` and applies a given function `f` to each character in the string, along with its index position in the string. The function `f` is provided by the user and must take two arguments: an unsigned integer representing the index and a character from the string. The function `f` is responsible for modifying or transforming the character as needed.
   - Return Value: It returns a new dynamically allocated string that contains the result of applying the function `f` to each character in the original string `s`. The original string `s` is not modified.
   - Example Usage:
     ```c
     char *original = "Hello";
     char *result = ft_strmapi(original, my_function);
     
     // Assuming my_function appends the index to each character
     // result will contain "H0e1l2l3o4"
     ```

2. `ft_striteri`:

   - Prototype: `void ft_striteri(char *s, void (*f)(unsigned int, char *));`
   - Purpose: `ft_striteri` stands for "string iterator with index." It takes a string `s` and applies a given function `f` to each character in the string, along with its index position in the string. The function `f` is provided by the user and must take two arguments: an unsigned integer representing the index and a pointer to the character from the string. Unlike `ft_strmapi`, `ft_striteri` modifies the characters in the original string `s` in place.
   - Return Value: `ft_striteri` does not return a value; it operates directly on the input string `s`.
   - Example Usage:
     ```c
     char my_string[] = "Hello";
     
     void my_function(unsigned int index, char *c) {
         *c = *c + index;
     }
     
     ft_striteri(my_string, my_function);
     // After the call, my_string will contain "Hfnos"
     ```

## [ft_putchar_fd](../libft/ft_putchar_fd.c)

A slight variation from ususal `ft_putchar` from Piscine. The `ft_putchar_fd` function is a simple utility function used to write a single character `c` to a specified file descriptor `fd`. It relies on the `write` system call or function to perform the actual output operation.

Usage Context:
- `ft_putchar_fd` is commonly used when you need to output a single character to a specific file descriptor, such as standard output (usually represented by `fd = 1`) or a file descriptor associated with a file or device.

Key Points:
- `char c`: The character to be written to the specified file descriptor.
- `int fd`: The file descriptor to which the character will be written.

How it Works:
- The function takes two arguments: the character `c` and the file descriptor `fd`.

- It uses the `write` system call (or function) to write the character `c` to the file descriptor specified by `fd`.

- The `write` function is provided with three arguments:
  - The file descriptor `fd` specifying where to write the data.
  - A pointer to the character `c` that you want to write.
  - The number `1` indicating the number of bytes to write, which corresponds to a single character.

- As a result, the `write` system call writes the character `c` to the specified file descriptor, allowing you to output characters to different destinations.

## [ft_putstr_fd](../libft/ft_putstr_fd.c)

The `ft_putstr_fd` function is used to write a null-terminated string `s` to a specified file descriptor `fd`. It relies on the `write` system call or function to perform the actual output operation.

Usage Context:
- `ft_putstr_fd` is commonly used when you need to output a string to a specific file descriptor, such as standard output (usually represented by `fd = 1`) or a file descriptor associated with a file or device.

Key Points:
- `char *s`: The null-terminated string to be written to the specified file descriptor.
- `int fd`: The file descriptor to which the string will be written.

How it Works:
- The function takes two arguments: the string `s` and the file descriptor `fd`.

- It begins by checking if the input string `s` is not NULL. If `s` is NULL, the function returns without performing any action, ensuring that it doesn't attempt to write a null pointer.

- If `s` is not NULL, the function proceeds to write the string to the specified file descriptor.

- It uses the `write` system call (or function) to write the entire string `s` to the file descriptor `fd`.

- The `write` function is provided with three arguments:
  - The file descriptor `fd` specifying where to write the data.
  - A pointer to the string `s` that you want to write.
  - The length of the string, determined by calling `ft_strlen(s)` to compute the number of bytes to write.

- As a result, the `write` system call writes the string `s` to the specified file descriptor, allowing you to output strings to different destinations.

- If `s` is a valid string, this function writes the entire string to the specified file descriptor.

In summary, `ft_putstr_fd` i.

## [ft_putendl_fd](../libft/ft_putendl_fd.c)

The `ft_putendl_fd` function is a utility function used to write a null-terminated string `s` followed by a newline character (`'\n'`) to a specified file descriptor `fd`. It relies on the `write` system call or function to perform the actual output operation.

Usage Context:
- `ft_putendl_fd` is commonly used when you need to output a null-terminated string followed by a newline character to a specific file descriptor, such as standard output (usually represented by `fd = 1`) or a file descriptor associated with a file or device.

Key Points:
- `const char *s`: The null-terminated string to be written to the specified file descriptor.
- `int fd`: The file descriptor to which the string and newline character will be written.

How it Works:
- The function takes two arguments: the null-terminated string `s` and the file descriptor `fd`.

- It first checks if the string `s` is not NULL. If `s` is NULL, the function returns without performing any action, which is a safety check to avoid writing to a NULL string.

- The function enters a loop that iterates through the characters of the string `s`.

- Inside the loop, for each character in `s`, it uses the `write` system call (or function) to write that character to the file descriptor specified by `fd`. It writes one character at a time.

- After writing all characters from the string, the function creates a `char` variable `nl` and assigns it the value of the newline character `'\n'`.

- It then uses the `write` function again to write the newline character `nl` to the specified file descriptor, ensuring that the output ends with a newline.

- The newline character is added to produce the effect of a line break, making it convenient for printing messages and ensuring proper formatting when writing text to a file or standard output.

## [ft_putnbr_fd](../libft/ft_putnbr_fd.c)

The two functions `ft_putnbr` from Piscine and `ft_putnbr_fd` serve a similar purpose: they convert an integer to a string representation and output that string to different destinations. However, they differ in a few key aspects:

1. **Output Destination**:
   - `ft_putnbr`: This function writes the string representation of the integer to the standard output (typically the console or terminal).
   - `ft_putnbr_fd`: This function writes the string representation of the integer to a specified file descriptor `fd`. It allows you to direct the output to a file or other output stream, not just the standard output.

2. **Size Limitation**:
   - `ft_putnbr`: This function does not have a fixed buffer size, but it relies on the stack for memory allocation during recursion. This can lead to a stack overflow if the integer is too large.
   - `ft_putnbr_fd`: It uses a fixed-size buffer (`str[13]`) to store the string representation.