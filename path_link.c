#include "shell.h"


/**
 * get_env- gets the value of the global variable
 * @name: name of the global variable
 *
 * Return: string of value
 */
char *get_env(const char *name)
{
	int x, y;
	char *num;

	if (!name)
		return (NULL);
	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (name[y] == environ[x][y])
		{
			while (name[y])
			{
				if (name[y] != environ[x][y])
					break;

				y++;
			}
			if (name[y] == '\0')
			{
				num = (environ[x] + y + 1);
				return (num);
			}
		}
	}
	return (0);
}


/**
 * add_node- adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 *
 * Return: address of the new element/node
 */

list_path *add_node(list_path **head, char *string)
{

	list_path *tmp;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!new || !string)
	{
		return (NULL);
	}

	new->dir = string;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}


/**
 * linkpath- creates a linked list for path directories
 * @path: string of path value
 *
 * Return: pointer to the created linked list
 */
list_path *linkpath(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _which- finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 *
 * Return: pathname of filename or NULL if no match
 */
char *_which(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

	while (tmp)
	{

		string = concat_all(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_list - frees a list_t
 *@head: pointer to our linked list
 */
void free_list(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}

}
