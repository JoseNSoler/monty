#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;




void pushMonty(stack_t **stack, unsigned int line_number);
void print_dlistint(stack_t **h);
void FreeStackMonty(stack_t *h);



int main(void)
{
        stack_t *stack;
        size_t n = 0;


        stack = NULL;
        pushMonty(&stack, 0);
        pushMonty(&stack, 1);
        pushMonty(&stack, 2);
        pushMonty(&stack, 3);
        pushMonty(&stack, 4);
        pushMonty(&stack, 5);

        print_dlistint(&stack);
        printf("number --> -%lu-\n", n);

        FreeStackMonty(stack);

        return(EXIT_SUCCESS);
}


void pushMonty(stack_t **stack, unsigned int line_number)
{
        stack_t *node = NULL;
        stack_t *tmp = *stack;

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

void print_dlistint(stack_t **h)
{
	size_t x = 0;
        stack_t *tmp = *h;

	while (tmp)
	{
		x++;
		printf("%d\n", tmp->n);
		tmp = tmp->next;
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
