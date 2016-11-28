#include <stdio.h>
#include <string.h>
#define INF 10000002

int v[102], map[102][102], dist, d[102];

void prim(int n)
{
    int i, j, min, st;
    memset(v, 0, sizeof(v));
    for(i = 1; i <= n; i++) d[i] = map[1][i];
    v[1] = 1;   dist = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;
        for (j = 1; j <= n; j++)
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
    int n, i, j , st ;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &st);
                map[i][j] = map[j][i] = st;
            }
        }
        prim(n);
        printf("%d\n", dist);
    }
    return 0;
}
