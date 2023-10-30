#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void verify_io_status(int status, int fd, char *filename, char appearance);

/**
 * main - Writing a program that copies the content of a file to another file
 * @argc: argument count input
 * @argv: argument variable input
 * Return: void
 */

int main(int argc, char *argv[])
{
int source, destination, count_read = 1024, wrote, close_source,
close_destination;
unsigned int appearance = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
char buff[1024];

if (argc != 3)
{
dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
exit(97);
}
source = open(argv[1], O_RDONLY);
verify_io_status(source, -1, argv[1], 'O');
destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, appearance);
verify_io_status(destination, -1, argv[2], 'W');
while (count_read == 1024)
{
count_read = read(source, buff, sizeof(buff));
if (count_read == -1)
verify_io_status(-1, -1, argv[1], 'O');
wrote = write(destination, buff, count_read);
if (wrote == -1)
verify_io_status(-1, -1, argv[2], 'W');
}
close_source = close(source);
verify_io_status(close_source, source, NULL, 'C');
close_destination = close(destination);
verify_io_status(close_destination, destination, NULL, 'C');
return (0);
}

/**
 * verify_io_status - program that checks if a file can be opened or closed
 * @status: file status
 * @filename: filename input
 * @appearance: file appearance
 * @fd: file describer
 * Return: 0 (Success)
 */

void verify_io_status(int status, int fd, char *filename, char appearance)
{
if (appearance == 'C' && status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
else if (appearance == 'O' && status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
exit(98);
}
else if (appearance == 'W' && status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
exit(99);
}
}
