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


int main ()
{
	int fd;
	char *str = "tam\nere";
	fd = open(FILE, O_RDONLY);
	//printf("%d\n",ft_line_size(fd));
	printf("%d\n", check_n(str));

	return (0);
}