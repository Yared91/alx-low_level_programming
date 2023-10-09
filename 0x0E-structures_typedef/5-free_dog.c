#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Writing a function that frees dogs
 * @d: struct input
 */

void free_dog(dog_t *d)
{
if (d)
{
free(d->name);
free(d->owner);
free(d);
}
}
