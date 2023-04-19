unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	k;

	k = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (size + ft_strlen(src));
	while (src[k] != '\0' && k < size - dest_len - 1)
	{
		dest[dest_len + k] = src[k];
		k++;
	}
	dest[dest_len + k] = '\0';
	return (dest_len + src_len);
}