#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * YE_cd - gets the change directory process
 * @cmd: command argument
 * Return: void
 */

void *YE_cd(char **cmd)
{
if (cmd[1] == NULL)
{
perror("Error");
}
else if (chdir((char *)cmd[0]) != 0)
{
fprintf(stderr, "Error changing directory");
}
return (0);
}
