#include "../libft.h"

char *ft_strcat(char *dest, const char *src)
{
    size_t dest_len = ft_strlen(dest);
    size_t src_len = ft_strlen(src);
    
    ft_memcpy(dest + dest_len, src, src_len + 1); // Copy including the null terminator
    
    return (dest);
}