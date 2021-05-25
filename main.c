#include "monty.h"

/**
 * main - Entry point for monty code
 * @argc: Count of arguments
 * @argv: Array-vector of arguments
 * 
 * Return: EXIT_SUCCESS on success - EXIT_FAILURE on `USAGE ERROR`
 */

int main(int argc, char *argv[])
{
        FILE *code_Monty = NULL;
        int status = 0;

        if(argc != 2)
                return(Err_Usage());

        code_Monty = fopen(argv[1], "r");

        if(!code_Monty)
                return(Err_File(argv[1]));
        
        status = TokenMonty(code_Monty);

        printf("FINALL%d %d \n",EXIT_SUCCESS, status);

        fclose(code_Monty);
        return(status);
        
}


void FreeStr_Monty(char *delStr)
{
        free(delStr);
}


/*
        fileName = malloc(sizeof(char) * (strlen(argv[1] + 1)));
        strcpy(fileName, argv[1]);
*/