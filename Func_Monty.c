#include "monty.h"

/**
 * 
 int LastNum(char *commandStr)
{
        int x = 0;

        while(commandStr[x])
        {
                if(commandStr[x] >= 48 && commandStr[x] <= 57)
                {
                        return (commandStr[x]);
                }
                x++;
        }
        return (0);
}
*/




void FreeMontyaa(int argc, char *argv, ...)
{

        int x = 0;
        va_list point;

        va_start(point, argv);
        
        for (x = 0; x < argc; x++)
        {
                free(((char *)va_arg(point, char *)));
        }
        va_end(point);
}





int MakeNumber(char *num, int delim, int line_number)
{

        char *number = NULL;
        int x = 0, value = 0, status = 0;

        /*printf("dentro de comando num %s %d \n", num, delim);*/


        if (num[delim - 1] == 10)
        {
                status = 1;
                number = malloc(sizeof(char) * (delim + 1));
                /*printf("saaaaaaaaaaaaaaaaaalto");*/
        }
        else
        {
                number = malloc(sizeof(char) * (delim + 1));
        }
        if (!number)
        {
                return(((Err_Malloc()) * (-1)));
        }

        if (status == 1)
        {
                for (x = 0;x < (delim + 1); x++)
                {       
                        if (num[x] == 10)
                                break;
                        if (num[x] < 48 || num[x] > 57)
                        {
                                free(number);
                                Err_NoInt(line_number);
                                return (-1);
                        }
                        number[x] = num[x];
                }
                number[delim - 1] = '\0';
        }
        else
        {
                for (x = 0;x < (delim); x++)
                {       
                        if (num[x] < 48 || num[x] > 57)
                        {
                                free(number);
                                Err_NoInt(line_number);
                                return (-1);
                        }
                        number[x] = num[x];
                }
                number[delim] = '\0';
        }

        /*printf("ultima linea char %d", number[delim - 1]);*/
        value = atoi(number);

        printf("final makenumber %s **%s** /%d/", num, number, value);
        free(number);
        return(value);
}





int ComparerString(char *s1, char *s2)
{
	int x = 0;
	int y = 0, z = 0;

	while (s1[x] != '\0')
	{
                if(s1[x] == 10)
                        break;
		x++;
	}

	for (; y < x; y++)
	{
		if (s1[y] == '\0' && s2[y] == '\0')
		{
			return (0);
		}
		if (s1[y] != s2[y] || s2[y] == '\0')
		{
			break;
		}
	}
	z = s1[y] - s2[y];
        /*printf("iniside -%d- , -%d-, -%d- /%s/", z, x, y, s1);*/
	return (z);
}


