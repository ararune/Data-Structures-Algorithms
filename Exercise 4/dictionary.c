#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Dictionary create()
{
    Dictionary createDict = (Dictionary)malloc(sizeof(Word));
    createDict->count = 0;
    createDict->word = NULL;
    createDict->next = NULL;
    return createDict;
}

void print(Dictionary dict)
{
    Dictionary tmp = dict;
    while (tmp != NULL)
    {
        printf("{%s}  count : %d \n", tmp->word, tmp->count);
        tmp = tmp->next;
    }
}

void destroy(Dictionary dict)
{
    Dictionary b = dict;
    while (dict != NULL)
    {
        b = dict;
        dict = dict->next;
        free(b->word);
        free(b);
    }
}

void add(Dictionary dict, char* str)
{
    Dictionary addDict = (Dictionary)malloc(sizeof(Word));

    addDict->word = _strdup(str);
    addDict->count = 1;

    if (dict->next == NULL)
    {
        addDict->next = dict->next;
        dict->next = addDict;
        return;
    }

    Dictionary temp = dict;
    while (temp->next != NULL) {
        if (strcmp(temp->next->word, str) < 0)
            temp = temp->next;

        else if (strcmp(temp->next->word, str) > 0)
        {
            addDict->next = temp->next;
            temp->next = addDict;
            return;
        }
        else if (strcmp(temp->next->word, str) == 0)
        {
            temp->next->count++;
            temp = temp->next;
            return;
        }

    }
    temp->next = addDict;
    temp->next->next = NULL;

}
int filter(Word* w) {
    return ((w->count > 5 && w->count < 10) && (strlen(w->word) > 3)) ? 1 : 0; 
}


Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w))
{
    Dictionary tmp = indict;
    if (indict->next == NULL)
        return indict;


    while (tmp->next != NULL)
    {
        if (filter(tmp->next) == 1)
            tmp = tmp->next;

        else {
            Dictionary tmp2 = tmp->next;
            tmp->next = tmp2->next;
            free(tmp2->word);
            free(tmp2);
        }
    }
    return indict;
}

