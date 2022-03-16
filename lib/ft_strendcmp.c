
#include "../include/so_long.h"

int		ft_strendcomp(const char *s1, const char *s2)
{
	unsigned long i;
	unsigned long start;

	i = 0;
	start = ft_strlen(s1) - ft_strlen(s2);
	while(s1[start + i])
	{
		if (s1[start + i] != s2[i])
			return(1);
		i++;
	}
	return (0);
}
