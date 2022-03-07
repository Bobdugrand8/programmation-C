#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringToInt(char *s)
{
    int res = 0, i = 0;
    while (s[i] != '\0')
    {
        res *= 10;
        res +=(int) s[i] - '0';
        i++;
    }
    return res;
}

int main()
{
    char *s = "1234";
    printf("%d\n",stringToInt(s));
    return 0;
}
