#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 10000000
int v[102], d[102], map[102][102];

void dijkstra(int n)
{
    int i, min, st, j;
    for(i = 1; i <= n; i++)
    {
        d[i] = map[1][i];
        v[i] = 0;
    }

    d[1] = 0;   v[1] = 1;
    for(i = 1; i <= n; i++)
    {
        st = 0; min = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] < min)
            {
                min = d[j]; st = j;
            }
        }
        v[st] = 1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > min + map[st][j])
            {
                d[j] = min + map[st][j];
            }
        }
    }
}
int main(void)
{
    char op[55];
    int i, j, n, ans = 0;

    scanf("%d", &n);
    ans = 0;
    memset(map,0, sizeof(map));
    for(i = 1; i < n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            scanf("%s", op);
            if(strcmp(op, "x") != 0)
                map[i + 1][j] = map[j][i +1 ] = atoi(op);
            else
                map[i + 1][j] = map[j][i + 1] = INF;
        }
    }
    dijkstra(n);
    for(i = 1; i <= n; i++)
    {
        if(ans < d[i])  ans = d[i];
    }
    printf("%d\n", ans);

    return 0;
}
