#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * SB - calls back the functions
 */

/**
 * collect_SB - calls all the builtins and functions
 * Return: shell builtins
 */

int collect_SB(void)
{
return (sizeof(shell_commands) / sizeof(struct SB));
}
