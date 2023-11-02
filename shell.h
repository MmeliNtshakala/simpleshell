#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char charecter);
void _puts(char *string);
int string_len(char *s);
char *_strdup(char *string);
char *concat_all(char *name, char *sep, char *value);

char **splitstring(char *string, const char *delim);
void execute(char **argv);
void *real_alloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *get_env(const char *name);
list_path *add_node(list_path **head, char *string);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

void(*c_build(char **arv))(char **arv);
int _atoi(char *s);
void escaping(char **arv);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);

void free_arv(char **arv);
void free_list(list_path *head);


#endif
