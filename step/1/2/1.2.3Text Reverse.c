#include <stdio.h>

char c[1002];
int main(void)
{
    int t, i, f, r, j;
    scanf("%d\n", &t);
    while(t--)
    {
        gets(c);
        f = 0;
        for(i = 0; c[i] != '\0';i++)
        {
            if(c[i] == ' ')
            {
                for(j = i - 1; j >= f; j--) printf("%c",c[j]);
                printf(" ");
                f = i + 1;
            }
        }
        for(j = i - 1; j >= f; j--) printf("%c", c[j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
