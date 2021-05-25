#ifndef __MONTY_H_
#define __MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>


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


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/* Functions */

int TokenMonty(FILE *code_Monty);
char *formater(char *commandStr, int line_number);

int ComparerString(char *s1, char *s2);

int MakeNumber(char *num, int delim, int line_number);
char *_strncpy(char *dest, char *src, int n);


/* Errors */

int Err_Usage(void);
int Err_File(char *fileName);
void Err_Command(char *commandErr, int line_number);
int Err_Malloc(void);
void Err_NoInt(int line_number);


/* Free */
void FreeStr_Monty(char *delStr);
void FreeMontyaa(int argc, char *argv, ...);

#endif
