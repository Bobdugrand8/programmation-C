#include <stdio.h>

int strlen(char *s)
{
    int res = 0;
    while (s[res] != '\0')
    {
        res++;
    }
    return res;
}



int main(int argc, char const *argv[])
{
    printf("longueur : %d\n",strlen("bob"));
    return 0;
}
