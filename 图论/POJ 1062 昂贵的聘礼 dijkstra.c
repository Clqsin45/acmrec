#include <stdio.h>
#include <string.h>
#define INF 0x7fffffff
int rank[102], v[102], d[102], map[102][102];
int limit, n;

int dijkstra(void)
{
    int i, j, st, min;
    for(i = 1; i <=n; i++)
    {
        d[i] = map[0][i];
       // printf("%d  %d\n", i, d[i]);
    }
    for(i = 1; i <= n; i++)
    {
        min = INF; st = -1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && min > d[j])
            {
                st = j;
                min = d[j];

            }
        }
        if(st == -1)    break;
        v[st] = 1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > d[st] + map[st][j] && map[st][j] > 0)
            {
                //printf("%d  %d\n", j, d[j]);
                d[j] = d[st] + map[st][j];
            }
        }
    }
    return d[1];
}
int main(void)
{
    int i, j ,st1, st2, m, max, ans = INF;
    while(scanf("%d%d", &limit, &n) != EOF)
    {
        memset(v, 0, sizeof(v));
        memset(rank, 0, sizeof(rank));
        memset(map, 0, sizeof(map));
        for(i = 0; i < 101; i++)
            d[i] = INF;

        for(i = 1; i <=n; i++)
        {
            scanf("%d%d%d", &map[0][i], &rank[i], &m);
            for(j = 1; j <= m ; j++)
            {
                scanf("%d%d", &st1, &st2);
                map[st1][i] = st2;
            }
        }
        for(i = 1; i <= n; i++)
        {
            max = rank[i];
            for(j = 1; j <= n; j++)
            {
                if(max < rank[j] || (max - rank[j]) > limit)
                {
                    v[j] = 1;
                }
                else v[j] = 0;
            }
            st1 = dijkstra();
            if(st1 < ans)   ans = st1;
        }

        printf("%d\n", ans);
    }

    return 0;
}
