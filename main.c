#include "get_next_line.h"

int          main(void)
{
   int fd;
   int ret;
   char *line;
   fd = open("/Users/vmusunga/Desktop/CODE/get_next_line/gnlTester/files/multiple_line_with_nl", O_RDONLY);
   while (1)
   {
      ret = get_next_line(fd, &line);
      printf("%d -- |%s|\n", ret, line);
      free(line);
      if (ret == 0)
         break;
   }
   return (0);
}