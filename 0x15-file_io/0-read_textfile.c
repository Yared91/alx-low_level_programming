#include "main.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads text file and prints it to the POSIX standard output
 * @filename: filename input
 * @letters: letters input
 * Return: actual number of letters it could read and print, unless 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
int file_x;
ssize_t dimenr, dimenw;
char *buff;

if (filename == NULL)
return (0);

file_x = open(filename, O_RDONLY);

if (file_x == -1)
return (0);

buff = malloc(sizeof(char) * letters);

if (buff == NULL)
{
close(file_x);
return (0);
}

dimenr = read(file_x, buff, letters);
close(file_x);

if (dimenr == -1)
{
free(buff);
return (0);
}

dimenw = write(STDOUT_FILENO, buff, dimenr);
free(buff);

if (dimenr != dimenw)
return (0);

return (dimenw);
}
