
#include "../include/so_long.h"

int	ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	needle;

	needle = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == needle)
			return (i);
		i++;
	}
	if (s[i] == 0 && needle == 0)
		return (i);
	return (0);
}