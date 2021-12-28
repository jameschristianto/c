#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *trim(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  // Is all spaces?
  if(*str == 0) return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

int main()
{
    char str[] = " james christiano ";
    printf("[%s]\n", trim(str));

    getchar();

    return 0;
}
