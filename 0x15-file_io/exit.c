#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * YE_exits - exits the process
 * @cmd: command argument
 * Return: void
 */

void *YE_exits(char **cmd)
{
fprintf(stderr, "Exiting process");
return (0);
}
