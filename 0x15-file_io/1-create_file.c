#include "main.h"

/**
 * create_file - Creating a function that creates a file
 * @filename: filename input
 * @text_content: text input
 * Return: 1 if Success, unless -1
 */

int create_file(const char *filename, char *text_content)
{
int file_x;
int count_letters;
int read_write;

if (!filename)
return (-1);

file_x = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

if (file_x == -1)
return (-1);

if (!text_content)
text_content = "";

for (count_letters = 0; text_content[count_letters]; count_letters++)
;
read_write = write(file_x, text_content, count_letters);

if (read_write == -1)
return (-1);

close(file_x);
return (1);
}
