#include <stdio.h>

int main(void)
{
    int nb = 0;
    char c = ' ';

    while (c != '.')
    {
        
        if (c == 'l')
        {
            c = getchar();
            if (c == 'e')
            {
                c = getchar();
                if (c == 's')
                    nb++;
            }
        } else {
            c = getchar();
        }
    }
    printf("il y a %d 'les' dans la suite donnée", nb);
}