#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * YE_env - finds the path
 * @cmd: command argument
 * Return: void
 */

void *YE_env(char **cmd)
{
char *envir = getenv("PATH");

if (cmd[0] == NULL)
{
perror("Error finding the path");
}
else
{
printf("%s", envir);
}
return (0);
}
