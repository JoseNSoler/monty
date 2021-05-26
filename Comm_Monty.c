#include "monty.h"


/**
 * get_op_func - analize 2 place on argv to find operator
 *
 * @s: operator to analize
 * Return: pointer to function corresponding to the rigth operator
*/

void (*exec_func(char *s))(stack_t ***stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int x = 0;

	while (ops[x].opcode)
	{
		if (ops[x].opcode == s)
                {
                        printf("esta es una linea %s %s", ops[x].opcode, s);
			return(ops[x].f);
                }
		x++;
	}

        return(NULL);

}

void push(stack_t ***stack, unsigned int line_number)
{
        stack_t *node = NULL;
        stack_t *tmp = *stack;

        printf("estamos dentro de pusssshshshsh \n");

        node = malloc(sizeof(stack_t));
        if (node == NULL)
                exit(EXIT_FAILURE);
        if (tmp == NULL)
        {
                node->next = NULL;
                node->prev = NULL;
                node->n = line_number;
                tmp = node;
                *stack = node;
        }
        else
        {
                node->next = tmp;
                node->prev = NULL;
                node->n = line_number;

                tmp->prev = node;
                tmp = node;
                *stack = node;
        }
}


/**
 * print_dlistint - prints a double list
 * @h: header of list
 *
 * Return: size of list --
 * for Holberton project
 */

void pall(stack_t ***stack, unsigned int line_number)
{
        stack_t **tmp = **stack;

	while (tmp)
	{
		line_number++;
		printf("%d\n", tmp->n);
		tmp = **tmp->next;
	}

}


/**
 * print_dlistint - prints a double list
 * @h: header of list
 *
 * Return: size of list --
 * for Holberton project
 */

void FreeStackMonty(stack_t *h)
{
        stack_t *tmp = h;

        while(h)
        {
                h = h->next;
                free(tmp);
                tmp = h;
        }

        free(h);
}
