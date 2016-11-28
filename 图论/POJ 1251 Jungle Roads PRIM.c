#include <stdio.h>
#include <string.h>
#define INF 1000002
int v[30], map[30][30], d[30], dist;

void prim(int n)
{
    int i, j, min, st;
    memset(v, 0, sizeof(v));
    for(i = 1; i <= n; i++) d[i] = map[1][i];
    v[1] = 1;   dist = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] < min)
            {
                st = j;
                min = d[j];
            }
        }
        v[st] = 1;
        dist += min;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > map[st][j])  d[j] = map[st][j];
        }
    }
}
int main(void)
{
    int n, t, i, j, st, x;
    char c;
    while(scanf("%d", &n) && n)
    {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                map[i][j] = INF;
        for(i = 1; i < n; i++)
        {   scanf("\n");
            scanf("%c %d", &c, &t);
            for(j = 1; j <= t; j++)
            {
                scanf(" %c %d", &c, &st);
               x =  c - 'A' + 1;
                map[i][x] = map[x][i] =st;
            }
            printf("###\n");
        }
        prim(n);
        printf("%d\n", dist);
    }
    return 0;
}
