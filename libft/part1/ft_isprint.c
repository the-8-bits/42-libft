#include "../libft.h"

int	ft_isprint(char *str)
{
    while (*str)
    {
        if (*str < 32 || *str > 126)
        {
            return (0);
        }
        str++;
    }
    return (1);
}