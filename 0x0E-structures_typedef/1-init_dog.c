#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Writing a function that initialize a variable of type struct dog
 * @d: pointer input
 * @name: name input
 * @age: age input
 * @owner: owner input
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
d = malloc(sizeof(struct dog));
d->name = name;
d->age = age;
d->owner = owner;
}
