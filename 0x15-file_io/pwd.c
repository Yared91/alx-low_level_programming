#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * YE_pwd - gets the present working directory process
 * @cmd: command argument
 * Return: void
 */

void *YE_pwd(char **cmd)
{
char AB[300];

if (cmd[0] == NULL)
{
perror("Error");
}
else if (getcwd((char *)cmd[0], sizeof(AB) != 0))
{
fprintf(stderr, "Error getting present working directory");
}
return (0);
}
