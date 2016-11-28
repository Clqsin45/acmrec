#include <stdio.h>
#include <string.h>
#define MAX 100005
int v[MAX];
int main(void)
{
    int c, n, i, j,  st, sum = 0, flag = 0;
    while(scanf("%d%d", &c, &n) && (c || n))
    {
        memset(v, -1, sizeof(v));
        sum = 0;    flag = 0;

        for(i = 1; i <= n; i++)
        {
            scanf("%d", &st);
            if(flag) continue;
            sum = (sum + st % c) % c;
            if(sum == 0)
            {
                for(j = 1; j <= i; j++)
                    printf("%d%c", j, j != i ? ' ' : '\n');
                flag = 1;
            }
            if(v[sum] != -1)
            {
                for(j = v[sum] + 1; j <= i; j++)
                    printf("%d%c", j, j != i ? ' ' : '\n');
                flag = 1;
            }
            v[sum] = i;
        }
    }
    return 0;
}
