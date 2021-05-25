/**
 * Err_Monty - Exit status and failure 
 *
 */

#include "monty.h"


/**
 * Err_Usage - returns `USAGE ERROR` on stderr
 *
 * Return: (EXIT_FAILURE)
 */

int Err_Usage(void)
{
	fprintf(stderr,"USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * Err_File - returns `FILE ERROR` on stderr
 *
 * Return: (EXIT_FAILURE)
 */

int Err_File(char *fileName)
{
	fprintf(stderr,"Error: Can't open file %s\n", fileName);
	return (EXIT_FAILURE);
}

/**
 * Err_File - returns `FILE ERROR` on stderr
 *
 * Return: (EXIT_FAILURE)
 */

void Err_Command(char *commandErr, int line_number)
{
	fprintf(stderr,"L%d: unknown instruction %s\n", line_number ,commandErr);
}

/**
 * Err_Malloc- returns failure on NULL malloc
 *
 * Return: (EXIT_FAILURE)
 */

int Err_Malloc(void)
{
	fprintf(stderr,"Error: malloc failed\n");
	return(EXIT_FAILURE);
}


/**
 * Err_Malloc- returns failure on NULL malloc
 *
 * Return: (EXIT_FAILURE)
 */

void Err_NoInt(int line_number)
{
	fprintf(stderr,"L%d: usage: push integer\n", line_number);
}