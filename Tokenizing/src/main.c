#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[] = "dog.cat.fish";
    char *tokenize = strtok(sentence, ".");

    while(tokenize != NULL){
        printf("%s\n", tokenize);
        tokenize = strtok(NULL, ".");
    }

    getchar();

    return 0;
}
