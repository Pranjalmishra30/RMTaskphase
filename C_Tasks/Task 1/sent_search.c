#include<stdio.h>
#include<string.h>
int main()
{
    char sent[40];
    char word[10];
    int i, j, found;
    int sentlen, wordlen;

    printf("Enter any string: ");
    gets(sent);
    printf("Enter any word to search: ");
    gets(word);

    sentlen  = strlen(sent);
    wordlen = strlen(word);

    for(i=0; i< sentlen-wordlen; i++)
    {
        found = 1;
        for(j=0; j<wordlen; j++)
        {
            if(sent[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }

        if(found == 1)
            printf("word found");
        else
            printf("word not found");
    }

}
