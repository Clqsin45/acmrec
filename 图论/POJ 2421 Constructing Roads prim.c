#include <stdio.h>
#include <string.h>
#define INF 10000002
int v[102], map[102][102], d[102], dist;

void prim(int n)
{
    int i, j, min, st;
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = map[1][i];
    }
    v[1] = 1; dist = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && min > d[j])
            {
                st = j;
                min = d[j];
            }
        }
        v[st] = 1;  dist += min;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > map[st][j])  d[j] = map[st][j];
        }
    }
}

int main(void)
{
    int n, m, i, j, st1, st2;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);
    scanf("%d", &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d", &st1, &st2);
        map[st1][st2] = map[st2][st1] = 0;
    }
    prim(n);
    printf("%d\n", dist);
    return 0;
}
