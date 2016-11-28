#include <stdio.h>
#include <string.h>
int a[150] = {0};
int main(void)
{
    int i, n = 0;  char c;
    while(scanf("%c", &c) != EOF )
    {
        a[c] ++;
        while(scanf("%c", &c))
        {
            if(c == '\n')   break;
            a[c]++;
        }
        for(i = 'a'; i <= 'z'; i++)
        {
            printf("%c:%d\n", i, a[i]);
        }
        printf("\n");
        memset(a,0,sizeof(a));
    }
    return 0;
}
