#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int nLines;
    //string readonly para reutilizar entre prints:
    const char* USAGE_STRING = "Use: -[FUNCTION] [#LINES]\n";
    switch (argc - 1)
    {
        case 0:{//no se pasaron argumentos:
            fputs(USAGE_STRING, stderr);
            return 1;
        }break;

        case 1://no se especificó el número de líneas:
            nLines = 10;   
        break;

        case 2://se especificó el número de líneas:
            nLines = atoi(argv[2]);
            //si el número de líneas es no-positivo, 
            //o no se pudo parsear como int el argumento i=2 introducido:
            if (nLines <= 0)
            {
                fputs("[#LINES] must be a positive integer\n", stderr);
                return 1;
            }
        break;

        default:{//demasiados argumentos:
            fprintf(stderr, "Too many arguments provided. %s", USAGE_STRING);
            return 1;
        }break;
    }
    
    //si argv[1] es "-head", ejecutar esa función
    if (strcmp(argv[1], "-head") == 0)
    {
        return head(nLines);
    }
    else if (strcmp(argv[1], "-tail") == 0)
    {
        return tail(nLines);
    }
    else if (strcmp(argv[1], "-longlines") == 0)
    {
        return longlines(nLines);   
    }
    //no está entre las funciones implementadas:
    else{
        fputs("Passed function name not recognized. Valid functions: -head, -tail, -longlines\n", stderr);
        return 1;
    }
}
