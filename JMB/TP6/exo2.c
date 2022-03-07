#include <stdio.h>

/*
Exo 2, 3 4
*/

int strcmp(char *s1, char *s2)
{
    int pos = 0;
    while (s1[pos] != '\0' || s2[pos] != '\0' )
    {
        if (s1[pos] < s2[pos] || s1[pos] == '\0'  )
            return 1;
        if (s1[pos] > s2[pos] || s2[pos] == '\0' )
            return -1;
        pos++;
    }
    return 0;
}

char *strcpy (char *dest, char *srce)
{
    int pos = 0;
    while(srce[pos] != '\0')
    {
        dest[pos] = srce [pos];
        pos++;
    }
    dest[pos] = '\0';
    return dest;
}

char *strcat(char *dest, char *srce)
{
    int decalage = 0;
    while (dest[decalage] != '\0')
    {
        decalage++;
    }
    int pos = 0
    while (srce[pos] != '\0')
    {
        dest[decalage+pos] = srce[pos]
        pos++;
    }
    dest[decalage+pos] = '\0';
    return dest;
}

int main(int argc, char const *argv[])
{
    printf("1 : %d\n", strcmp("bob", "cha"));
    printf("1 : %d\n", strcmp("bobiiii", "bob"));
    printf("1 : %d\n", strcmp("bob", "bobi"));
    printf("1 : %d\n", strcmp("bobc", "bobiiii"));
    printf("1 : %d\n", strcmp("bob", "bob"));


    char * s1;
    printf("2: %s  ",stmcpy(s1,"test"));
    printf("2: %s  ",strcat(s1," test"));

    return 0;
}
