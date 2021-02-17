#include "get_next_line.h"

int		ft_read_count(int fd)
{
	char buffer;
	int i;

	i = 0;

	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n' || buffer == '\0')
			break;
		i++;
	}
	return (i);
}

int		check_n(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*append_till_n2(char *src, char n)
{
	int x;
	char *dst;

	x = 0;
	while(src[x] && src[x] != n)
		x++;
	if (!(dst = malloc(sizeof(char) * (x + 1))))
		return (NULL);
	x = 0;
	while(src[x] && src[x] != n)
	{
		dst[x] = src[x];
		x++;
	}
	return (dst);
}

int main ()
{
	int fd;
	char *str = "tagrossem\nere";
	fd = open(FILE, O_RDONLY);
	//printf("%d\n",ft_line_size(fd));
	printf("%s\n", append_till_n2(str, '\n'));

	return (0);
}