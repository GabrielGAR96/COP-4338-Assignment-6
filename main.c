#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binsearch(char* dictionaryWords[],int listSize,char* keyword){
    int mid, low = 0, high = listSize - 1;
    while (high >= low)
    {
        mid = (high + low) / 2;
        if (strcmp(dictionaryWords[mid],keyword) < 0)
            low = mid + 1;
        else if (strcmp(dictionaryWords[mid],keyword)>0)
            high = mid - 1; else
        return mid;
    }
    return -1; //not found
}

int spellCheck(char* word, char* dictionaryFileName)
{
    char* words[99999];
    char line[99999];
    FILE *fp;
    fp = fopen(dictionaryFileName, "r");

    int index = 0;
    while (fgets(line, 99999, fp)) {
        words[index] = malloc(sizeof(FILE));
        char *tmp = strdup(line);
        if(tmp[strlen(tmp)-1] == '\n') tmp[strlen(tmp)-1] = '\0';
        strcpy(words[index], tmp);
        index++;
    }

    if(binsearch(words, index, word) != -1)
        return 1;
    return 0;
}

int main() {

    char input[100];
    char directory[200] =  "/Users/gabrielgar/CLionProjects/untitled16/dictionary.txt";
    printf("Insert word\n");
    scanf("%s", input);

    if(spellCheck(input, directory))
        printf("Word spelled correctly!\n");
    else printf("Word spelled incorrectly!\n");

    return 0;
}