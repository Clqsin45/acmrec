#include <stdio.h>
#define INF 14000
int sum[INF] = {0};
int prim[1440];
int main(void)
{
    int i, j, sign, m = 1, st, n;
      prim[1] = 2;
    for(i = 3; i < INF; i+= 2)
    {
        sign = 1;
        for(j = 1; j <= m; j++)
        {
            if(i % prim[j] == 0)
            {
                sign = 0;
                break;
            }
        }
        if(sign)
        {
            prim[++m] = i;
        }
    }
    for(i = 1; i <= m; i++)
    {
        st = prim[i];   sum[st]++;
        for(j = i + 1; j <= m; j++)
        {
            if(st + prim[j] < INF)
            {
                sum[st + prim[j]]++;
                st += prim[j];
            }
            else break;
        }
    }
    while(scanf("%d", &n) && n)
    {
        printf("%d\n", sum[n]);
    }
    return 0;
}
