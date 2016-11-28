#include <stdio.h>

#define MAX 1000002
int tb[MAX] = {0};
int main(void)
{
    int  n, i, j,k, ct = 0;
    int sign;
    for(i = 2; i < MAX; i++)
    {
        if(tb[i]) continue;
        ct ++;
        for(j = i; j < MAX; j += i)     tb[j] = ct;
    }

    while(scanf("%d", &n) != EOF)
    {
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", tb[n]);
    }
    return 0;
}
