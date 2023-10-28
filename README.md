---
title: Libft
tags:
  - "42"
  - programação
  - common_core
use: README, Documentation
languages: C
dependences:
---

#to_review

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

> [!INFO] 
> If you spot something that isn't right, please open an [Issue](https://github.com/the-8-bits/42-libft/issues/new)

</br>

<details><summary>Table of Contents 🔖</summary>

- [**Libft**](#libft)
  - [Purpose](#purpose)
  - [Elements](#elements)
    - [Helpers Functions #to\_review](#helpers-functions-to_review)
    - [Makefile #to\_review](#makefile-to_review)

</details>

---

## Purpose

The objective of this repo is to register the progress during the 42 Cursus. Here is the [Subject](subject.md).
## Elements

I'll divide the code explanations in each Part's folder, to reduce the amount of text and make the documents more modular, to that please refer to the links in the headers of this table:

| [Part 1](./docs/PART1.md) |  #  | [Part 2](./docs/PART2.md) |  #  | [Bonus](./docs/BONUS.md) |  #  |
| --------------------------------- |:---:| --------------------------------- |:---:| -------------------------------- |:---:|
| ft_isalpha                        | ✔️  | ft_substr                         | ✔️  | ft_lstnew                       | ✔️  |
| ft_isdigit                        | ✔️  | ft_strjoin                        | ✔️  | ft_lstadd_front                 | ✔️  |
| ft_isalnum                        | ✔️  | ft_strtrim                        | ✔️  | ft_lstsize                      | ✔️  |
| ft_isascii                        | ✔️  | ft_split                          | ✔️  | ft_lstlast                      | ✔️  |
| ft_isprint                        | ✔️  | ft_itoa                           | ✔️  | ft_lstadd_back                  | ✔️  |
| ft_strlen                         | ✔️  | ft_strmapi                        | ✔️  | ft_lstdelone                    | ✔️  |
| ft_memset                         | ✔️  | ft_striteri                       | ✔️  | ft_lstclear                     | ✔️  |
| ft_bzero                          | ✔️  | ft_putchar_fd                     | ✔️  | ft_lstiter                      | ✔️  |
| ft_memcpy                         | ✔️  | ft_putstr_fd                      | ✔️  | ft_lstmap                       | ✔️  |
| ft_memmove                        | ✔️  | ft_putendl_fd                     | ✔️  |                                 | ✔️  |
| ft_strlcpy                        | ✔️  | ft_putnbr_fd                      | ✔️  |                                 |     |
| ft_strlcat                        | ✔️  |                                   |     |                                  |     |
| ft_toupper                        | ✔️  |                                   |     |                                  |     |
| ft_tolower                        | ✔️  |                                   |     |                                  |     |
| ft_strchr                         | ✔️  |                                   |     |                                  |     |
| ft_strrchr                        | ✔️  |                                   |     |                                  |     |
| ft_strncmp                        | ✔️  |                                   |     |                                  |     |
| ft_memchr                         | ✔️  |                                   |     |                                  |     |
| ft_memcmp                         | ✔️  |                                   |     |                                  |     |
| ft_strnstr                        | ✔️  |                                   |     |                                  |     |
| ft_atoi                           | ✔️  |                                   |     |                                  |     |

### Helpers Functions #to_review

Are defined inside the "main" functions, maybe I'll add to the `libft.h` file as independent functions.

- Inside of `ft_split`
  - `static size_t h_count_words(const char *s, char c)`, counts the number of words in a given input string `s` based on a specified delimiter character `c`. It iterates through the characters in the input string and increments a count whenever it encounters the beginning of a new word, defined as a sequence of characters not equal to `c`. It returns the total count of words found in the string.
  - `void	h_actual_split(s, c, split, split_index)`, is responsible for splitting the input string `s` at a delimiter character `c` and storing the resulting substring in the `split` array at the specified `split_index`.

- Inside of `ft_strtrim`
  - `static int	ft_char_in_set(char c, const char *set)`, checks if a given character `c` is present in a provided set of characters specified by the string `set`. It iterates through the characters in the `set` string and returns `1` if it finds a match with the character `c`, indicating that `c` is in the set. If no match is found after checking all characters in the `set`, it returns `0`, indicating that `c` is not in the set.

- Inside of `ft_itoa`
  - `static void ft_strrev (char *str)`, reverses the characters in a given string `str` in-place. It calculates the length of the string, then uses two pointers (`start` and `end`) to swap characters from the beginning and end of the string, moving towards the center of the string until they meet. This effectively reverses the order of characters in the `str` variable.

### Makefile #to_review

Used for building a static library named `libft.a` from the collection of C source files. This file can be divided into a few parts as shown below:

1. `NAME = libft.a`: Defines the name of the static library that will be built.

2. `CFLAGS = -Wall -Werror -Wextra -I. -c`: Specifies compiler flags for compilation. These flags include enabling warnings (`-Wall`), treating warnings as errors (`-Werror`), enabling extra warnings (`-Wextra`), and specifying the include directory (`-I.`). The `-c` flag is used to compile source files into object files.

3. `PART_1`, `PART_2`, `BONUS`, `PERSONAL`: These variables list the source files that will be compiled to create the object files. Each section corresponds to different parts of the library.

4. `OBJ_1`, `OBJ_2`, `OBJ_BONUS`, `OBJ_PERSONAL`: These variables specify the corresponding object files that will be generated from the source files in the `PART_1`, `PART_2`, `BONUS`, and `PERSONAL` sections.

5. `FILES`: Combines all the source files from different sections into one list.

6. `OBJ`: Combines all the object files from different sections into one list.

7. `all: $(NAME)`: This is the default target, which means that when you run `make` without specifying a target, it will build the `$(NAME)` target, which is the static library.

8. `$(NAME): $(OBJ)`: This rule specifies how to build the static library `$(NAME)` from the object files `$(OBJ)`. It uses the [`ar` command](https://www.mkssoftware.com/docs/man1/ar.1.asp) to create the library with the flags:
    - `-r`, replaces or adds file to archive. If archive does not exist, `ar` creates it and prints a message. When `ar` replaces an existing member, it does not change the archive order. If file is not replacing a member, `ar` adds it to the end of the archive (unless you specify `-a`, `-b`, or `-i`). This option regenerates the symbol table.
    - `-c`, suppresses the message ar normally prints when it creates a new archive file. You can only use this in conjunction with the `-r` and `-q` options.
    - `-s`, regenerates the symbol table regardless of whether the command modifies the archive.

9.  `%.o: %.c`: This is a generic rule for building object files from C source files. It specifies that any `.o` file depends on a corresponding `.c` file, and it compiles the `.c` file into an object file.

10. `clean`: This target removes all object files (`.o` files) generated during the compilation process.

11. `fclean: clean`: This target performs a clean operation and also removes the generated library file (`$(NAME)`).

12. `re: fclean all`: This target performs a clean (`fclean`) operation and then rebuilds the library (`all`).

13. [`.PHONY` targets](https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html): These are special targets that are not files but are used to specify that the associated targets (`clean`, `fclean`, `all`, `re`) are not filenames and should always be executed, even if a file with the same name exists.

To build the static library `libft.a`, you can simply run `make`. If you want to clean up generated files, you can use `make clean` or `make fclean` to remove object files and the library, respectively. To rebuild everything from scratch, you can use `make re`.


> Κωκυτός