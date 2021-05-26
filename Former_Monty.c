/**
 * Exec_Monty - Executes monty code
 *
 */

#include "monty.h"

/* */

int TokenMonty(FILE *code_Monty, stack_t *stack)
{
        char *line_buf = NULL;
        char *copy_line = NULL;
        char *command = NULL;
        size_t line_buf_size = 0;
        int line_count = 0;
        ssize_t line_size;
        int status = 0;


        line_size = getline(&line_buf, &line_buf_size, code_Monty);
        while (line_size >= 0)
        {
                /* Increment our line count */
                line_count++;
                copy_line = malloc(sizeof(char) * (strlen(line_buf) + 1));
                if (!copy_line)
                {
                        FreeStr_Monty(line_buf);
                        FreeStr_Monty(command);
                        FreeStr_Monty(copy_line);
                        return(Err_Malloc());
                }
                strcpy(copy_line, line_buf);
                /* Show the line details */


                command = formater(copy_line, line_count, &stack);


                printf("final commando %d %s %s -%s- aaa %d \n", line_count, line_buf, copy_line, command, status);

                /* next line */
                line_size = getline(&line_buf, &line_buf_size, code_Monty);

                FreeStr_Monty(copy_line);
                if (!command || command == NULL)
                {
                        FreeStr_Monty(line_buf);
                        FreeStr_Monty(command);
                        return(EXIT_FAILURE);
                }

                /* llamado a la funcion  execMonty(command)*/
                /* if (!copy_line = malloc(sizeof(char) * (strlen(line_buf) + 1))) return */
                /* return() */

                FreeStr_Monty(command);
        }
        FreeStr_Monty(line_buf);


        return EXIT_SUCCESS;
}


/* */

char *formater(char *commandStr, int line_number, stack_t **header)
{
        const char del[2] = " ";
        int x = 0, lastChar = 0, lastNum = 0, value = 0;
        unsigned int Fvalue = 0;
        char* montyCommands[3] = {"push", "pall"};
        char *tokenMonty = NULL, *valueMonty = NULL, *command = NULL, *copyComm = NULL;

        copyComm = malloc(sizeof(char) * (strlen(commandStr) + 1));
        if(!copyComm)
        {
                Err_Malloc();
                return(NULL);
        }

        strcpy(copyComm, commandStr);
        tokenMonty = strtok(commandStr, del);
        /* Iterate over arguments */
        while (tokenMonty)
        {
                lastChar = ((int)(strlen(tokenMonty) - 1));
                /* Copy only text avoiding `jump line` */
                if (tokenMonty[lastChar] == 10)
                {
                        command = malloc(sizeof(char) + (lastChar));
                        if(!command)
                        {
                                FreeStr_Monty(command);
                                FreeStr_Monty(copyComm);
                                Err_Malloc();
                                return(NULL);
                        }
                        strncpy(command, tokenMonty, lastChar);
                        command[lastChar] = '\0';
                        printf("Al final %d", command[lastChar]);
                }
                else
                {
                        command = malloc(sizeof(char) + (lastChar + 1));
                        if(!command)
                        {
                                FreeStr_Monty(command);
                                FreeStr_Monty(copyComm);
                                Err_Malloc();
                                return(NULL);
                        }
                        strcpy(command, tokenMonty);
                }
                printf("ultima linea %d", command[lastChar - 1]);

                /* Iterate searching coincidences on pre-defined commands[] */
                while (montyCommands[x])
                {
                        /* coincidence */ 
                        if (ComparerString(command, montyCommands[x]) == 0)
                        {
                                FreeStr_Monty(copyComm);
                                /* command -push- */
                                if ((montyCommands[x] == montyCommands[0]) && (ComparerString(command, montyCommands[0]) == 0))
                                {
                                        valueMonty = tokenMonty;
                                        valueMonty = strtok(NULL,del);
                                        lastNum = ((int)(strlen(valueMonty)));
                                        /* Copy only text avoiding `jump line` */
                                        printf("another one %s \n", valueMonty);
                                        if (valueMonty[(int)(strlen(valueMonty) - 1)] == 10)
                                        {
                                                printf("salto desde monty %d", valueMonty[((int)(strlen(valueMonty) - 1))]);
                                                value = MakeNumber(valueMonty, (lastNum), line_number);
                                        }
                                        else
                                                value = MakeNumber(valueMonty, lastNum, line_number);

                 
                 
                                        Fvalue = ((int)value);
                                        printf("-------------------///%d", Fvalue);
                                        if(value < 0)
                                        {
                                                FreeStr_Monty(command);
                                                return(NULL);
                                        }
                                }
                                /* command -pall- */
                                
                                if ((montyCommands[x] == montyCommands[1]) && (ComparerString(command, montyCommands[1]) == 0))
                                {
                                        printf("pallasaaa");
                                }
                                exec_func(montyCommands[x])(&header, Fvalue);

                                printf("anotheroneee %s %s %d \n", tokenMonty, montyCommands[x], value);
                                return(command);
                        }
                        x++;
                }
                FreeStr_Monty(command);
                x = 0;
                tokenMonty = strtok(NULL, del);
        }
        printf("error no comadno encontrado -%s-", commandStr);
        Err_Command(copyComm, line_number);
        FreeStr_Monty(copyComm);
        return(NULL);
}


/**
 *
 *
 * 
 *
 */
