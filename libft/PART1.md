---
title: Libft - Part 1
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

- [Part 1](#part-1)
  - [ft\_isalpha](#ft_isalpha)
  - [ft\_isdigit](#ft_isdigit)
  - [ft\_isalnum](#ft_isalnum)
  - [ft\_isascii](#ft_isascii)
  - [ft\_isprint](#ft_isprint)
  - [ft\_strlen](#ft_strlen)
  - [ft\_memset](#ft_memset)
  - [ft\_bzero](#ft_bzero)
  - [ft\_memcpy](#ft_memcpy)
  - [ft\_memmove](#ft_memmove)
  - [ft\_strlcpy](#ft_strlcpy)
  - [ft\_strlcat](#ft_strlcat)
  - [ft\_toupper](#ft_toupper)
  - [ft\_tolower](#ft_tolower)
  - [ft\_strchr](#ft_strchr)
  - [ft\_strrchr](#ft_strrchr)
  - [ft\_strncmp](#ft_strncmp)
  - [ft\_memchr](#ft_memchr)
  - [ft\_memcmp](#ft_memcmp)
  - [ft\_strnstr](#ft_strnstr)
  - [ft\_atoi](#ft_atoi)
  - [ft\_calloc](#ft_calloc)
  - [ft\_strdup](#ft_strdup)

---

# Part 1

## [ft_isalpha](./ft_isalpha.c)

This is one of the functions developed during the Piscine, this one though has a slight modification.

-   **Loop Condition**: Instead of initializing a counter variable `i` to 0 and using `str[i]` to access characters, we directly use a pointer `str` and loop while the value it points to is not the null terminator (`'\0'`). The null terminator marks the end of the string.
-   **Character Validation Condition**: In the original version, the condition for checking whether a character is an alphabetic character was complex and involved two separate logical conditions. In the optimized version, this condition is simplified. It uses logical operators (`&&` and `||`) to combine the checks for lowercase and uppercase alphabetic characters.
    The original condition:
    ```c
    if ((str[i] <= 'a' || str[i] >= 'z') && (str[i] <= 'A' || str[i] >= 'Z'))
    ```
    
    The optimized condition:
    ```c
    if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
    ```
    
    This optimized condition first checks whether the character is not within the range of lowercase (`'a'` to `'z'`) and not within the range of uppercase (`'A'` to `'Z'`) alphabetic characters. If either of these conditions is true (using `||`), it means the character is not an alphabetic character, so the `if` statement is satisfied.
-   **Incrementing Pointer**: After checking the current character, whether it's alphabetic or not, we increment the `str` pointer to point to the next character in the string.
-   **Return Value**: Remains the same:
	- if the loop completes without encountering any non-alphabetic characters, the function returns `1`, indicating that the entire string consists of alphabetic characters.
	- If the loop encounters a non-alphabetic character, it immediately returns `0` to indicate that the string contains non-alphabetic characters.


## [ft_isdigit](./ft_isdigit.c)

Same as `isalpha()` situation:
-   **Loop Condition**: Just like before, we use a pointer `str` to traverse the string while the character it points to is not the null terminator (`'\0'`).
-   **Character Validation Condition**: The condition for checking whether a character is a digit is simplified using logical operators (`&&` and `!`).
    The original condition:
    ```c
    if (str[i] <= '0' || str[i] >= '9')
    ```
    
    The optimized condition:
    ```c
    if (!(*str >= '0' && *str <= '9'))
    ```
    
    The optimized condition checks if the character is not within the range of digits (`'0'` to `'9'`). If this condition is true, it means the character is not a digit, and the `if` statement is satisfied.
-   **Incrementing Pointer**: Similar to the previous optimized version, we increment the `str` pointer to point to the next character in the string.
-   **Return Value**: 
	- If the loop completes without encountering any non-digit characters, the function returns `1`, indicating that the entire string consists of digits.
	- If the loop encounters a non-digit character, it immediately returns `0` to indicate that the string contains non-digit characters.

## [ft_isalnum](./ft_isalnum.c)

I think now you already got it, don't you?

-   **Loop Condition**: Just like before, we use a pointer `str` to traverse the string while the character it points to is not the null terminator (`'\0'`).
-   **Character Validation Condition**: The condition for checking whether a character is an alphanumeric character is simplified using logical operators (`&&`, `||`, and `!`).
    
    The original condition:
    ```c
    if (((str[i] <= 'a' || str[i] >= 'z') &&
        (str[i] <= 'A' || str[i] >= 'Z')) ||
        (str[i] <= '0' || str[i] >= '9'))
    ```
    
    The optimized condition:
    ```c
    if (!(((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) ||
          (*str >= '0' && *str <= '9')))
    ```
    
    The optimized condition combines checks for both alphabetic characters and digits using logical operators. If this combined condition is true, it means the character is not an alphanumeric character, and the `if` statement is satisfied.

## [ft_isascii](./ft_isascii.c)

The `ft_isascii` function takes an integer `c` as input. The return statement directly evaluates the condition `(c >= 0 && c <= 127)`.
- If `c` is greater than or equal to 0 and less than or equal to 127 (the ASCII range), the condition is true, and the function returns `1`.
- If `c` is outside the ASCII range, the condition is false, and the function returns `0`.

## [ft_isprint](./ft_isprint.c)

The difference is now the range, checking whether a character is a printable ASCII character is kept the same.

The original condition:
```c
if (str[i] < 32 || str[i] > 126)
```

The optimized condition:
```c
if (*str < 32 || *str > 126)
```

The optimized condition directly checks whether the character `*str` (the value pointed to by `str`) is less than 32 or greater than 126, which corresponds to the non-printable and extended ASCII range. If this condition is true, it means the character is not printable, and the `if` statement is satisfied.

## [ft_strlen](./ft_strlen.c)

This function returns the lengh of the string. The only change here is a better naming of the variables.

In this optimized version:

1. We use a `const char *ptr` pointer to traverse the string. Using `const` indicates that we don't intend to modify the string.

2. We use a `while` loop to iterate through the string until we reach the null terminator `'\0'`.

3. We calculate the length of the string by subtracting the original pointer `str` from the current pointer `ptr`. This difference represents the number of characters in the string.

This optimized version maintains the functionality of the original code while improving code readability and efficiency.

> [!INFO]
> I've seen a data type called `size_t` that "can store the maximum size of a theoretically possible object of any type. That's a guarantee that comes with the type". But don't know if Moulinette aproves the `return` type.

## [ft_memset](./ft_memset.c)

It fills a given block of memory with a specified value up to a certain length. The function takes the starting memory address, the value to fill, and the length as arguments, and then uses a loop to set each byte in the memory block to the specified value. Finally, the modified memory block's starting address is returned.

**Input**: Takes three arguments:

- `block`: A pointer to the memory block that needs to be filled.
- `value`: The value that will be written to each byte of the memory block.
- `length`: The number of bytes to fill in the memory block.

1. The function first casts the `block` pointer to an unsigned char pointer `ptr`, which allows for individual byte-level manipulation.
2. The `i` variable is used as an index to iterate through the memory block.  
3. Then, inside the `while` loop, the code assigns the specified `value` to the byte at the current position in the memory block using pointer arithmetic and then increments the index `i`.  
4. After filling the entire block, the function returns the original pointer `block`.

## [ft_bzero](./ft_bzero.c)

This function is used to clear a specific amount of memory by setting all the bytes within that memory range to zero. It's commonly used to clear sensitive data or initialize memory buffers before use, especially in cases where security and predictability of data are important.

**Input**: Takes two parameters:
- a pointer `block` to the start of the memory block
- and a `size_t` value `n` representing the number of bytes to set to zero. 


1.   The code checks if `n` is zero. If it is, there's no memory to set to zero, so the function immediately returns.    
2.   A local character pointer `ptr` is declared and initialized with the value of the pointer `block`. This pointer will be used to traverse through the memory block.    
3.   Then enters a loop that will iterate `n` times. Within each iteration, it sets the value at the memory location pointed to by `ptr + i` to zero. The `i` is incremented after each assignment. 
4.   The loop continues until `i` reaches the value of `n`, effectively setting `n` bytes of memory to zero.


## [ft_memcpy](./ft_memcpy.c)

Used to copy a specified number of bytes from a source memory location to a target memory location.

The function is declared with the following parameters:    
-   `target`: A pointer to the memory where the data will be copied to.
-   `source`: A pointer to the memory from which the data will be copied.
-   `n`: The number of bytes to be copied.


Inside the function:    
-   `i` is a variable of type `size_t` that will be used to iterate through the bytes to be copied.
-   `ptr` is a pointer to a character (byte), initially set to point to the starting address of the `target` memory.
-   `ptr2` is a pointer to a character (byte), initially set to point to the starting address of the `source` memory.

The `while` loop runs `n` times, as the goal is to copy `n` bytes from the source to the target memory.  Within the loop `*(ptr + i) = *(ptr2 + i);`: This line copies the byte at the `i`th position from the source memory (pointed to by `ptr2`) to the target memory (pointed to by `ptr`). It's effectively copying individual bytes.

After the loop completes, the function returns the original `target` pointer. This indicates that the target memory now holds a copy of the specified bytes from the source memory.

## [ft_memmove](./ft_memmove.c)

The function `ft_memmove` is a memory manipulation function. Its purpose is to copy a specified number of bytes from one memory location (`src`) to another (`dst`), even if the source and destination memory regions overlap. Overall, `ft_memmove` is a versatile memory copy function that ensures safe copying of data even when there is an overlap between source and destination memory regions. This makes it suitable for various applications where data integrity is essential, such as working with arrays, strings, or dynamic memory allocation. Here's a brief explanation of its usage and context:

Usage Context:
- `ft_memmove` is commonly used in C programming when you need to copy a block of memory from one location to another, especially when you cannot guarantee that the source and destination memory regions won't overlap.

Key Points:
- `void *dst`: A pointer to the destination memory location where the data will be copied.
- `const void *src`: A pointer to the source memory location from which data will be copied.
- `size_t len`: The number of bytes to copy from `src` to `dst`.

How it Works:
- The function first checks if `src` is located before `dst` in memory. If `src` comes before `dst`, it performs a backward copy (from the end of the buffer towards the beginning) to avoid overwriting data before it's copied.

- If `src` is after `dst` in memory, it performs a forward copy (from the beginning to the end).

- It uses a loop to copy each byte one at a time.

- The function returns a pointer to the destination memory location `dst` after the copy is complete.


## [ft_strlcpy](./ft_strlcpy.c)

The `ft_strlcpy` function is designed to copy a source string (`src`) into a destination string (`dest`) while ensuring that it doesn't exceed a specified size limit (`size - 1`). It provides a safe way to copy strings, preventing buffer overflows by specifying a size limit. It returns the length of the source string, which can be useful in various string manipulation tasks.

Usage Context:
- `ft_strlcpy` is typically used when you want to copy a string from `src` to `dest` while ensuring that the destination buffer (`dest`) doesn't overflow its specified size limit (`size - 1`), and you still want to know the length of the source string.

Key Points:
- `char *dest`: A pointer to the destination buffer where the string will be copied.
- `const char *src`: A pointer to the source string that needs to be copied.
- `unsigned int size`: The size of the destination buffer, indicating the maximum number of characters that can be copied (including the null-terminator).

How it Works:
- If `size` is zero, it returns the length of the source string using the `ft_strlen` function. This is a special case to handle.

- It initializes pointers `d` (for destination) and `s` (for source) to the start of their respective strings.

- It uses a loop to copy characters from `src` to `dest` one by one until one of the following conditions is met:
  - The end of the source string (`*s` becomes `'\0'`).
  - The destination buffer is full (`size - 1` characters copied).
  
- After the copy, it ensures that the destination string is null-terminated by setting `*d` to `'\0'`.

- Finally, it calculates and returns the length of the source string using the `ft_strlen` function.

Optimizations made of the previous Piscine code:

1. We use pointer variables (`ptr`, `d`, and `s`) to navigate through the strings instead of integer indices, which can be more efficient.
2. In `ft_strlcpy`, we check if `size` is $0$ upfront and return the length of the source string without copying if it is, which is the expected behavior of `strlcpy`.
3. We use `const` for the `src` parameter in both functions because these functions should not modify the source string.

## [ft_strlcat](./ft_strlcat.c)

The `ft_strlcat` function is designed to concatenate two strings, `src` and `dest`, while ensuring that the total length of the resulting string does not exceed a specified size limit (`size - 1`). It returns the total length of the concatenated string.

Usage Context:
- `ft_strlcat` is typically used when you want to concatenate two strings, `src` and `dest`, while ensuring that the destination buffer (`dest`) does not overflow its specified size limit (`size - 1`). It returns the total length of the concatenated string.

Key Points:
- `char *dest`: A pointer to the destination buffer where the strings will be concatenated.
- `char *src`: A pointer to the source string that will be concatenated to `dest`.
- `unsigned int size`: The size of the destination buffer, indicating the maximum number of characters that can be added to `dest` (including the null-terminator).

How it Works:
- It initializes counters (`count`), and variables for the lengths of `src` and `dest`.

- If the length of `dest` is greater than or equal to `size`, it returns `size + ft_strlen(src)`. This means that there is not enough space in `dest` to concatenate `src`, and it returns the total length that would have resulted if the concatenation was successful.

- It enters a loop to copy characters from `src` to `dest`, one by one, until one of the following conditions is met:
  - The end of the source string (`src[count]` becomes `'\0'`).
  - The destination buffer is full (`count` reaches `size - dest_len - 1` to leave space for the null-terminator).

- After the copy, it ensures that the destination string is null-terminated by setting `dest[dest_len + count]` to `'\0'`.

- Finally, it returns the total length of the concatenated string, which is the sum of the lengths of `src` and `dest` after the concatenation.

Optimizations made of the previous Piscine code:

1. Improved readability
2. Changed counter variable

It provides a safe way to concatenate strings while preventing buffer overflows by specifying a size limit.

## [ft_toupper](./ft_toupper.c)

The `ft_toupper` function is designed to convert all lowercase letters in a given string to their corresponding uppercase equivalents in the ASCII character set. It does this by checking each character in the input string and modifying it if it's a lowercase letter.

Usage Context:
- `ft_toupper` is typically used when you want to convert a string to uppercase characters. This can be useful in various text processing tasks, such as standardizing input data or ensuring consistent formatting.

Key Points:
- `char *str`: A pointer to the input string that you want to convert to uppercase. The function modifies this string in place.

How it Works:
- The function initializes a counter variable `counter` to zero.

- It enters a loop that iterates through each character in the input string until it encounters the null-terminator (`'\0'`), indicating the end of the string.

- Inside the loop, it checks if the current character `str[counter]` is a lowercase letter. It does this by comparing its ASCII value to the range of lowercase letters ('a' to 'z').

- If the character is indeed a lowercase letter, it subtracts 32 from its ASCII value. This adjustment is based on the ASCII character encoding, where the difference between uppercase and lowercase letters is 32. This effectively converts the lowercase letter to its corresponding uppercase letter.

- The function increments the `counter` to move to the next character in the string.

- After processing all characters in the string, it returns a pointer to the modified input string `str`. The string has now been converted to uppercase in place.

Optimizations made of the previous Piscine code:

1. Improved readability
2. Changed counter variable

It's a simple utility function for converting all lowercase letters in a string to uppercase letters. It operates in place, directly modifying the input string.

## [ft_tolower](./ft_tolower.c)

Like [ft_toupper](#ft_toupper), but the inverse operation.

Optimizations made of the previous Piscine code:

1. Improved readability
2. Changed counter variable

## [ft_strchr](./ft_strchr.c)

The `ft_strchr` function is designed to search for the first occurrence of a specific character (`c`) in a given string (`s`). It returns a pointer to the first occurrence of the character within the string or a NULL pointer if the character is not found. It's a useful tool for string manipulation and text processing tasks.

Usage Context:
- `ft_strchr` is typically used when you need to find the position of a specific character within a string or determine if a character exists in the string.

Key Points:
- `const char *s`: A pointer to the input string where the character will be searched for.
- `int c`: The character to search for, **specified as an integer**, i.e. the ASCII value.

How it Works:
- The function enters a loop that iterates through each character in the input string `s` until it encounters the null terminator (`'\0'`), indicating the end of the string.

- Inside the loop, it checks if the current character pointed to by `*s` matches the character `c` that it's searching for. If there's a match, it returns a pointer to the location of the character within the string.

- If the loop completes without finding the character and reaches the end of the string, it checks if the character `c` is the null terminator (`'\0'`). If it is, it returns a pointer to the end of the string. This is useful for cases where you want to find the null terminator itself.

- If none of the above conditions are met, it means the character `c` was not found in the string, so it returns a NULL pointer to indicate that.

Written in this way, the code avoids the declaration of a counter variable. 

## [ft_strrchr](./ft_strrchr.c)

The `ft_strrchr` function is designed to search for the last occurrence of a specified character `c` in a given string `s`. It returns a pointer to the last occurrence of the character in the string or a pointer to the null terminator if the character is not found.

Usage Context:
- `ft_strrchr` is typically used when you want to find the last occurrence of a specific character within a string or check for the presence of the null terminator in the string.

Key Points:
- `const char *s`: A pointer to the input string in which you want to search for the character.
- `int c`: The character to search for (as an integer).

How it Works:
- The function initializes a pointer `last_occurrence` to `NULL` to keep track of the last occurrence of the character `c` in the string.

- It enters a loop that iterates through each character in the input string `s` until it reaches the null terminator (`'\0'`), which marks the end of the string.

- Inside the loop, it checks if the current character `*s` is equal to the character `c` being searched for. If a match is found, it updates the `last_occurrence` pointer to point to the current position in the string. This way, it keeps track of the last occurrence encountered while continuing to search the string.

- After processing all characters in the string, the function checks if `c` is the null terminator itself (`(char)c == '\0'`). If it is, this means we are looking for the null terminator, and it returns a pointer to the current position in the string (the end of the string).

- Finally, the function returns either a pointer to the last occurrence of the character `c` or `NULL` if the character is not found in the string.

In summary, `ft_strrchr` provides a simple way to search for the last occurrence of a character in a string and returns a pointer to it. If the character is not found, it returns `NULL`. Additionally, it can be used to check for the presence of the null terminator in the string when `c` is `'\0'`.

## [ft_strncmp](./ft_strncmp.c)

The `ft_strncmp` function is designed to compare two strings `s1` and `s2` up to a specified number of characters `n`. It returns an integer that indicates the result of the comparison. This function is similar to the standard library function `strncmp`.

Usage Context:
- `ft_strncmp` is typically used when you want to compare two strings for equality or determine their order in lexicographical (dictionary) order, but only up to a certain number of characters.

Key Points:
- `char *s1`: A pointer to the first string to compare.
- `char *s2`: A pointer to the second string to compare.
- `unsigned int n`: The maximum number of characters to compare.

How it Works:
- The function initializes a counter variable `counter` to zero to keep track of the characters being compared.

- It enters a loop that compares characters from both strings `s1` and `s2` one by one, as long as `n` is greater than zero and the characters match. It also ensures that it doesn't compare beyond the null terminators of either string.

- Inside the loop, it increments `counter` and decrements `n` for each character compared.

- After exiting the loop, the function checks two conditions:
  - If `n` has reached zero, it means that the specified number of characters has been compared, and the function returns `0` to indicate that the strings are equal up to `n` characters.
  - If both `s1` and `s2` have reached their null terminators (end of the strings) at the same position, it also returns `0` to indicate equality up to that point.

- If neither of the above conditions is met, it returns the integer result of subtracting the ASCII value of the differing characters in `s1` and `s2`. This result indicates the lexicographical order of the two strings or the difference between the first differing characters.

In summary, `ft_strncmp` is used to compare two strings up to a specified number of characters. It returns `0` if the strings are equal up to that point, a negative value if `s1` is lexicographically smaller than `s2`, and a positive value if `s1` is lexicographically greater than `s2`. It allows for controlled string comparison, which can be useful in sorting or searching algorithms.

In this optimized version:

1. The variable `i` changed to `counter` to improve readability.

2. If `n` reaches $0$ or both strings are null-terminated at the same position, we return $0$ to indicate equality.

    ```c
    while (n > 0 && s1[counter] != '\0' && s1[counter] == s2[counter])
    {
        counter++;
        n--;
    }

    if (n == 0 || (s1[counter] == '\0' && s2[counter] == '\0'))
        return (0);
    ```

3. If the loop exits without a match and `n` is still greater than $0$, we return the difference between the corresponding characters in `s1` and `s2`, as specified by the comparison.
    ```c
    return (int)(s1[counter] - s2[counter]);
    ```

## [ft_memchr](./ft_memchr.c)

The `ft_memchr` function is designed to search for the first occurrence of a specified character `c` in a memory block of a specified size `n`. It returns a pointer to the first occurrence of the character in the memory block or `NULL` if the character is not found.

Usage Context:
- `ft_memchr` is typically used when you want to search for a specific character within a memory block of a certain size. This function is particularly useful when working with binary data or when you need to locate a specific byte in a memory region.

Key Points:
- `const void *s`: A pointer to the memory block in which you want to search for the character.
- `int c`: The character to search for (as an integer).
- `size_t n`: The maximum number of bytes to search within the memory block.

How it Works:
- The function begins by converting the input pointer `s` to a `const unsigned char *` pointer (`ptr`). This is done to ensure that the comparison inside the loop works with unsigned characters, as it is common in memory manipulation functions.

- It also converts the character `c` to an `unsigned char` (`unchar`) to avoid any sign extension issues during comparison.

- The function enters a loop that iterates through the memory block pointed to by `ptr` while `n` is greater than zero.

- Inside the loop, it checks if the current byte pointed to by `ptr` is equal to the `unchar` character being searched for. If a match is found, it returns a pointer to the location in memory where the character `c` was first encountered. This indicates a successful search.

- After processing each byte, the function decrements `n` and advances the `ptr` to point to the next byte in memory.

- If the character `c` is not found in the specified number of bytes or if `n` is zero initially, the function returns `NULL` to indicate that the character was not found in the memory block.

## [ft_memcmp](./ft_memcmp.c)

The `ft_memcmp` function is designed to compare two blocks of memory, `s1` and `s2`, up to a specified number of bytes `n`. It returns an integer that indicates the result of the comparison. This function is similar to the standard library function `memcmp`.

Usage Context:
- `ft_memcmp` is typically used when you want to compare two blocks of memory for equality or determine their order in memory, but only up to a certain number of bytes.

Key Points:
- `const void *s1`: A pointer to the first memory block to compare.
- `const void *s2`: A pointer to the second memory block to compare.
- `size_t n`: The maximum number of bytes to compare.

How it Works:
- The function begins by converting the input pointers `s1` and `s2` to `const unsigned char *` pointers (`p1` and `p2`). This is done to ensure that the comparison inside the loop works with unsigned characters, as it is common in memory manipulation functions.

- The function enters a loop that iterates through the memory blocks pointed to by `p1` and `p2` while `n` is greater than zero.

- Inside the loop, it checks if the current bytes pointed to by `p1` and `p2` are equal. If they are not equal, it returns the difference between the bytes as an integer. This result indicates the order of the memory blocks.

- After processing each byte, the function decrements `n` and advances both `p1` and `p2` to point to the next bytes in memory.

- If the memory blocks are equal up to the specified number of bytes or if `n` is zero initially, the function returns `0` to indicate equality up to that point.

## [ft_strnstr](./ft_strnstr.c)

The `ft_strnstr` function is designed to search for the first occurrence of a substring `little` within a larger string `big`, but with a specified maximum length `len` for the search. It returns a pointer to the first occurrence of `little` within `big` (within the specified `len`) or `NULL` if `little` is not found.

Usage Context:
- `ft_strnstr` is typically used when you want to search for a substring within a larger string, but you want to limit the search to a specific maximum length. This function is similar to `strnstr` from the C standard library.

Key Points:
- `const char *big`: A pointer to the larger string in which you want to search for `little`.
- `const char *little`: A pointer to the substring you want to find within `big`.
- `size_t len`: The maximum number of characters to consider in `big` for the search.

How it Works:

- The function first checks if `little` is an empty string by examining the first character. If `little` is empty, it immediately returns a pointer to the beginning of `big`. This is a special case where the empty string is considered to be found anywhere within `big`.

    ```c
    if (!*little)
        return ((char *)big); // Return a pointer to the beginning of big if little is an empty string
    ```

- It initializes two counters, `b_counter` for `big` and `l_counter` for `little`.

- And enters a loop that iterates through the characters in `big` while `b_counter` is less than `len` and `big[b_counter]` is not the null terminator (`'\0'`). This ensures that the search is limited to the specified length `len` and that we don't exceed the end of `big`.

    ```c
    while (big[b_counter] && b_counter < len)
	{
		l_counter = 0;
        // Second loop
		b_counter++;
	}
    ```

- Inside the loop, it checks if the characters in `big` starting from `big[b_counter]` match the characters in `little`. It does this by comparing `big[b_counter + l_counter]` with `little[l_counter]`. It also ensures that we don't exceed the end of `big` (`b_counter + l_counter < len`).

    ```c
    while (big[b_counter + l_counter] == little[l_counter] && b_counter + l_counter < len)
    {
        if (little[l_counter + 1] == '\0')
            return (char *)(big + b_counter); // Return a pointer to the first occurrence of little within big
        l_counter++;
    }
    ```

- If a match is found and all characters in `little` are successfully matched, it returns a pointer to the first occurrence of `little` within `big` by adding `b_counter` to the pointer to `big`.

- If no match is found within the current search range, the function increments `b_counter` to continue searching.

- If the loop completes without finding `little` within `big` within the specified `len`, it returns `NULL` to indicate that `little` is not found.

## [ft_atoi](./ft_atoi.c)

The `ft_atoi` function is designed to convert a string representation of an integer into an actual integer value. It handles whitespace, signs (positive or negative), and the digits of the number.

Usage Context:
- `ft_atoi` is typically used when you have a string that represents an integer value, and you need to convert it into an actual integer value for further processing. It's commonly used in parsing user input or reading data from text files.

Key Points:
- `char *str`: A pointer to the string that represents the integer to be converted.

How it Works:
- The function initializes two variables: `sign` for the sign of the number (initialized to positive), and `result` for storing the converted integer value (initialized to $0$).

- It enters a loop to skip leading whitespace characters, such as spaces and various control characters (tab, newline, etc.). The loop continues until a non-whitespace character is encountered.

- It then handles the sign of the number. If the first character after whitespace is '-' (negative sign) or '+' (positive sign), it sets the `sign` accordingly and advances the `str` pointer past the sign character.

- The function then enters another loop to convert the digits to an integer. It checks if the character pointed to by `str` is a digit ($0$ to $9$) and, if so, adds it to the `result`. It does this by multiplying the current `result` by $10$ and adding the numeric value of the digit (achieved by subtracting '0' from the character).

- The loop continues until a non-digit character is encountered.

- Finally, the function returns the calculated `result` multiplied by the `sign`, which accounts for the sign of the number.

In this optimized version:

1. I've used `sign` instead of `negative` to keep track of the sign of the number, where $1$ represents positive and $-1$ represents negative.

2. I've combined the logic for handling the sign of the number and skipping leading whitespace characters, from:

    ```c
    while ((str[count] > 8 && str[count] < 14) || (str[count] == 32))
		count++;
	while ((str[count] != '\0') && (str[count] == '+' || str[count] == '-'))
	{
		if (str[count] == '-')
			negative++;
		count++;
	}
    ```

    to:

    ```c
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1; // Negative sign
		str++;
	}
    ```

3. I've simplified the conversion of digits to an integer by multiplying the existing result by $10$ and adding the new digit, from:
    ```c
    while ((str[count] != '\0') && (str[count] >= 48 && str[count] <= 57))
	{
		//subtrai 48(0) p/ buscar a distancia p/ o 0
		//no prox ciclo o numero passado vai aumentar uma dezena
		number = number * 10 + str[count] - 48;
		count++;
	}
    ```

    to:

    ```c
    while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
    ```

4. The function now returns `result * sign` to return the final integer value with the correct sign.

This version of `ft_atoi` is more concise, easier to read, and retains the functionality of converting strings to integers.

## [ft_calloc](./ft_calloc.c)

The `ft_calloc` function is designed to allocate memory for an array of elements, each of a specified `size`, and initialize all the bytes in the allocated memory to zero. It is similar to the standard library function `calloc`.

Usage Context:
- `ft_calloc` is typically used when you need to allocate memory for an array of elements and want to ensure that the allocated memory is initialized to zero. This is often used when working with dynamic arrays or buffers that need to be zeroed out initially.

Key Points:
- `size_t nmemb`: The number of elements to allocate memory for.
- `size_t size`: The size (in bytes) of each element.

How it Works:
- The function first calculates the total size needed for the allocated memory by multiplying the number of elements (`nmemb`) by the size of each element (`size`). This gives the total number of bytes required for the array.

- It then uses `malloc` to allocate memory for the array, specifying the `total` size. If memory allocation fails (when `malloc` returns `NULL`), the function returns `NULL` to indicate the failure.

- After successful memory allocation, the function uses `ft_bzero` (a custom function that sets a range of memory bytes to zero) to initialize all the bytes in the allocated memory to zero. This step ensures that the memory is properly zeroed out before it is used.

- Finally, the function returns a pointer to the allocated and zero-initialized memory, which can be used as an array of elements. It's the caller's responsibility to free the memory when it's no longer needed using `free`.


## [ft_strdup](./ft_strdup.c)


The `ft_strdup` function is designed to duplicate (create a copy of) a given string `s` and return a pointer to the newly allocated duplicate string. It allocates memory for the duplicate string using `malloc` and then copies the contents of the original string into the newly allocated memory.

Usage Context:
- `ft_strdup` is typically used when you want to create a duplicate (copy) of a given string, often for the purpose of safely modifying one copy without affecting the other or for storing the original string for reference.

Key Points:
- `const char *s`: A pointer to the input string that you want to duplicate.

How it Works:
- The function first calculates the size needed for the duplicate string by adding 1 to the length of the original string using `ft_strlen(s) + 1`. This extra 1 accounts for the null terminator at the end of the string.

- It then allocates memory for the duplicate string using `malloc` and stores the pointer to the allocated memory in the `dup` variable. If memory allocation fails (when `malloc` returns `NULL`), the function returns `NULL` to indicate the failure.

- Next, the function uses `ft_memcpy` to copy the contents of the original string `s` into the newly allocated memory `dup`. It copies `size` bytes, which includes the null terminator, to ensure that the duplicate string is null-terminated.

- Finally, the function returns a pointer to the duplicate string, which is now a separate copy of the original string, allocated in dynamic memory. It's the caller's responsibility to free the memory when it's no longer needed using `free`.


> In general I've tried to avoid using ASCII values as magical numbers, there's no need of doing that and it only affects the code clarity.