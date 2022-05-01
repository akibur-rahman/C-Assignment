#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringOperation(char string1[], char string2[], int str1size, int str2size);

void main()
{
    FILE *fPointer;
    fPointer = fopen("test.txt", "r");
    char singleLine[150], string1[150], string2[150];
    int length_of_string1 = 0, length_of_string2 = 0, i;
    // reading strings by lines
    strcpy(string1, fgets(singleLine, 150, fPointer));

    strcpy(string2, fgets(singleLine, 150, fPointer));

    fclose(fPointer);
    // calculating string length of strings
    for (i = 0; string1[i] != '\0'; i++)
    {
        length_of_string1++;
    }
    for (i = 0; string2[i] != '\0'; i++)
    {
        length_of_string2++;
    }

    stringOperation(string1, string2, length_of_string1, length_of_string2); // called stringOperation function and passed two strings and their size;
}

void stringOperation(char string1[], char string2[], int str1size, int str2size)
{

    char outputString[150], outputString_1[150], outputString_2[150], leftHalf_string1[75], rightHalf_string1[75], leftHalf_string2[75], rightHalf_string2[75];
    int i, j, k, mid_of_string_1, mid_of_string_2, length_of_output_string = 0;

    // splitting first string into two equal parts
    mid_of_string_1 = str1size / 2;

    for (i = 0; i < mid_of_string_1; i++)
    {
        leftHalf_string1[i] = string1[i];
    }
    leftHalf_string1[i] = '\0';

    for (i = mid_of_string_1, k = 0; i <= str1size; i++, k++)
    {
        rightHalf_string1[k] = string1[i];
    }

    // splitting second string into two equal parts
    mid_of_string_2 = str2size / 2;

    for (i = 0; i < mid_of_string_2; i++)
    {
        leftHalf_string2[i] = string2[i];
    }
    leftHalf_string2[i] = '\0';

    for (i = mid_of_string_2, k = 0; i <= str2size; i++, k++)
    {
        rightHalf_string2[k] = string2[i];
    }

    // Adding first half of Strings
    for (i = 0; i <= mid_of_string_1; i++)
    {
        outputString_1[i] = leftHalf_string1[i];
    }

    for (i = 0; i <= mid_of_string_2; i++)
    {
        outputString_1[mid_of_string_1 + i] = leftHalf_string2[i];
    }
    // adding second half of strings
    for (i = 0; i <= mid_of_string_1; i++)
    {
        outputString_2[i] = rightHalf_string1[i];
    }

    for (i = 0; i <= mid_of_string_2; i++)
    {
        outputString_2[mid_of_string_1 + i] = rightHalf_string2[i];
    }
    // adding final strings
    for (i = 0; i <= str1size; i++)
    {
        outputString_1[i] = outputString_1[i];
    }

    for (i = 0; outputString[i] != '\0'; i++) // calculating the length of output string
    {
        length_of_output_string++;
    }

    for (i = 0; i <= length_of_output_string; i++)
    {
        outputString[length_of_output_string + i] = outputString_2[i];
    }

    // Writing data on final.txt file
    FILE *fPointer;
    fPointer = fopen("final.txt", "w");
    fprintf(fPointer, outputString);
    fclose(fPointer);
}
