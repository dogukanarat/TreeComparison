#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeLibrary/AvlTree.h"
#include "TreeLibrary/SplayTree.h"

char *file1Content = NULL;
size_t file1Size = 0;
char *file2Content = NULL;
size_t file2Size = 0;

int32_t* inputArray1 = NULL;
size_t inputArray1Size = 0;
int32_t* inputArray2 = NULL;
size_t inputArray2Size = 0;

// Main_ReadTextFile reads a text file and returns the contents.
int32_t Main_ReadTextFile(const char *filename, char **buffer, size_t *bufferSize)
{
    FILE* textFile = NULL;
    long numOfBytes = 0;

    textFile = fopen(filename, "rb");

    if (textFile == NULL)
        return FALSE;

    fseek(textFile, 0L, SEEK_END);

    numOfBytes = ftell(textFile);

    fseek(textFile, 0L, SEEK_SET);

    *buffer = (char *)calloc(numOfBytes, sizeof(char));

    if (*buffer == NULL)
        return FALSE;
    
    *bufferSize = numOfBytes;

    fread(*buffer, sizeof(char), numOfBytes, textFile);

    fclose(textFile);

    return TRUE;
}

int32_t Main_ConvertStringToIntArray(char *stringBuffer, int32_t** array, size_t* arraySize)
{
    char *token = NULL;
    char *stringBufferCopy = NULL;
    size_t numOfTokens = 0;

    stringBufferCopy = (char *)calloc(strlen(stringBuffer), sizeof(char));

    if (stringBufferCopy == NULL)
        return FALSE;

    strcpy(stringBufferCopy, stringBuffer);

    token = strtok(stringBufferCopy, " ");

    while (strcmp(token, "\n"))
    {
        numOfTokens++;
        token = strtok(NULL, " ");
    }

    *array = (int32_t *)calloc(numOfTokens, sizeof(int32_t));

    if (*array == NULL)
        return FALSE;
    
    *arraySize = numOfTokens;

    strcpy(stringBufferCopy, stringBuffer);

    token = strtok(stringBufferCopy, " ");

    for (size_t i = 0; i < numOfTokens; i++)
    {
        (*array)[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    free(stringBufferCopy);

    return TRUE;
}

int main(int argc, char **argv)
{
    AvlTree avlTree1;
    SplayTree splayTree1;
    AvlTree avlTree2;
    SplayTree splayTree2;

    AvlTree_Init(&avlTree1);
    SplayTree_Init(&splayTree1);

    AvlTree_Init(&avlTree2);
    SplayTree_Init(&splayTree2);

    int resultReadFile1 = Main_ReadTextFile("input1.txt", (char **)&file1Content, &file1Size);
    int resultReadFile2 = Main_ReadTextFile("input2.txt", (char **)&file2Content, &file2Size);

    Main_ConvertStringToIntArray(file1Content, &inputArray1, &inputArray1Size);
    Main_ConvertStringToIntArray(file2Content, &inputArray2, &inputArray2Size);

    // Insert inputArray1
    for(int counter = 0; counter < inputArray1Size; counter++)
    {
        // printf("%d ", inputArray1[counter]);
        AvlTree_Insert(&avlTree1, inputArray1[counter], 1);
        SplayTree_Insert(&splayTree1, inputArray1[counter], 1);
    }

    // Insert inputArray2
    for(int counter = 0; counter < inputArray2Size; counter++)
    {
        // printf("%d ", inputArray1[counter]);
        AvlTree_Insert(&avlTree2, inputArray2[counter], 1);
        SplayTree_Insert(&splayTree2, inputArray2[counter], 1);
    }

    printf("Output1: \n");

    // Print avlTree1
    printf("Avl Tree: \n");
    AvlTree_Print(&avlTree1);
    printf("\n");
    printf("Total Cost: %d\n", AvlTree_GetTotalCost(&avlTree1));

    printf("\n\n");

    // Print splayTree1
    printf("Splay Tree: \n");
    SplayTree_Print(&splayTree1);
    printf("\n");
    printf("Total Cost: %d\n", SplayTree_GetTotalCost(&splayTree1));

    printf("\n\n");

    printf("Output2: \n");

    // Print avlTree2
    printf("Avl Tree: \n");
    AvlTree_Print(&avlTree2);
    printf("\n");
    printf("Total Cost: %d\n", AvlTree_GetTotalCost(&avlTree2));

    printf("\n\n");

    // Print splayTree2
    printf("Splay Tree: \n");
    SplayTree_Print(&splayTree2);
    printf("\n");
    printf("Total Cost: %d\n", SplayTree_GetTotalCost(&splayTree2));

    printf("\n\n");

    return 0;
}