#include <stdio.h>
#define INF 10000002
int v[502], map[505][505], d[505], max;

void prim(int n)
{
    int i, j, st, min;
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = map[1][i];
    }
    v[1] = 1;   max = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && min > d[j])
            {
                st = j; min = d[j];
            }
        }
        v[st] = 1;
        if(max < min)   max = min;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > map[st][j])
                d[j] = map[st][j];
        }
    }
}

int main(void)
{
    int tc, n, i, j;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                scanf("%d", &map[i][j]);
        prim(n);
        printf("%d\n", max);
    }
    return 0;
}
