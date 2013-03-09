#include <stdio.h>
#include "read_line.h"

int main()
{
    char **line;
    ReadLineStatus status = READ_LINE_SUCCESS;
    status = read_line(stdin, line);
    printf("%s", *line);
    return 0;
}
