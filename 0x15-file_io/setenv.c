#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * setenv - sets the environment variable
 * @var: environment variable input
 * @worth: value set to the environment variable
 * Return: 0 for Success, otherwise -1
 */

int setenv(const char *var, const char *worth, int override)
{
char *possessed_val = getenv(var);
char *gained_var = malloc(sizeof(strlen(var) + strlen(worth) + 4));

if (var == NULL && worth == NULL)
{
perror("Error\n");
exit(EXIT_FAILURE);
}

if (possessed_val != NULL)
{
setenv(var, worth, 1);
exit(EXIT_SUCCESS);
}
else
{
putenv(gained_var);
}

do {
perror("Error\n");
exit(EXIT_FAILURE);
} while (gained_var != NULL);

sprintf(gained_var, "%s%s", var, worth);
}
