#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define INF 10000002

int map[1002][1002], d[1002], v[1002];
void dijkstra(int n)
{
    int i, j, min, st;
    for(i = 1; i <= n; i++)
    {
        d[i] = map[1][i];
        v[i] = 0;
    }
    v[1] = 1; d[1] = 0;
    for(i = 1; i <= n; i++)
    {
        min = INF;  st = 1;
        for(j = 1; j <= n;j++)
        {
            if(!v[j] && d[j] < min)
            {
                st = j;
                min = d[j];
            }
        }
        v[st] = 1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > d[st] + map[st][j])  d[j] = d[st] + map[st][j];
        }
    }
}

int main(void)
{
    int n, m,i , j , st1, st2, stt;

    scanf("%d%d", &m, &n);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++) map[i][j] = map[j][i] = INF;
    }
    for(i = 1; i <=m; i++)
    {
        scanf("%d%d%d", &st1, &st2, &stt);
        if(stt < map[st1][st2])
        {
            map[st1][st2] = map[st2][st1] = stt;
        }
    }
    dijkstra(n);
    printf("%d\n", d[n]);
    return 0;
}
