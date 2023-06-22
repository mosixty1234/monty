#include "monty.h"

/**
 * my_strdup - duplicates a string
 * @str: the string to be duplicated
 * Return: dup
 */

char *my_strdup(const char *str)
{
	char *dup;
	size_t slen;

	slen = strlen(str) + 1;
	dup = malloc(slen * sizeof(char));

	if (dup != NULL)
		memcpy(dup, str, slen);

	return (dup);
}
