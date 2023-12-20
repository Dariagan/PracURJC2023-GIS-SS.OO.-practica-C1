#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

char* readMultipleLines()
{
    char lineBuffer[512];
    char* wholeReadString = malloc(sizeof(char));
    wholeReadString[0] = '\0';

    while (fgets(lineBuffer, sizeof(lineBuffer), stdin) != NULL)
    {
        wholeReadString = (char*)realloc(wholeReadString, strlen(wholeReadString) + strlen(lineBuffer) + 1);
        strcat(wholeReadString, lineBuffer);
    }
    return wholeReadString;
}

int checkN(int N){
    if (N < 0) {
        fprintf(stderr, "Error: N must be a positive integer\n");
        return 1;
    }
    else return 0;
}

int head(int N)
{
    char* wholeReadString;
    int charI;
    
    if (checkN(N) == 1) return 1;

    wholeReadString = readMultipleLines();
    
    for (charI = 0; charI < strlen(wholeReadString) && N > 0; charI++)
    {
        putchar(wholeReadString[charI]);
        N -= wholeReadString[charI] == '\n';
    }
    free(wholeReadString);
 
    return 0;
}

int tail(int N)
{
    char* wholeReadString;
    int charI;
        
    if (checkN(N) == 1) return 1;

    wholeReadString = readMultipleLines();
    const unsigned int READ_STRING_LENGTH = strlen(wholeReadString);

    N += wholeReadString[READ_STRING_LENGTH-1] == '\n';
    
    for (charI = READ_STRING_LENGTH - 1; charI >= 0 && N > 0; charI--)
    {
        N -= wholeReadString[charI] == '\n';
    }

    for (charI += 2; charI <= READ_STRING_LENGTH; charI++)
    {
        putchar(wholeReadString[charI]);
    }
    free(wholeReadString);

    return 0;
}

int longlines(int N)
{
    char* wholeReadString, *temp;
    char** longestLines = NULL;

    unsigned int i, j, linesCount;
        
    if (checkN(N) == 1) return 1;

    wholeReadString = readMultipleLines();

    temp = strtok(wholeReadString, "\n");
    for (i = 0; temp != NULL; i++)
    {
        if (i == 0)
            longestLines = malloc(sizeof(char*));
        else
            longestLines = realloc(longestLines, sizeof(char*) * (i+1));

        longestLines[i] = temp;

        temp = strtok(NULL, "\n");
    }
    linesCount = i;

    for (i = 0; i < linesCount - 1; i++) {
        for (j = 0; j < linesCount - i - 1; j++) {
            if (strlen(longestLines[j]) < strlen(longestLines[j+1])) 
            {
                temp = longestLines[j]; 
                longestLines[j] = longestLines[j+1];
                longestLines[j+1] = temp;
            }
        }
    }

    for (i = 0; i < N && i < linesCount; i++)
        puts(longestLines[i]);

    free(wholeReadString);
    free(longestLines);
    return 0;
}
