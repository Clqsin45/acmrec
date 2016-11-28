#include <stdio.h>
#define INF 1000000
int map[102][102], v[102], d[102], dist;

void prim(int n)
{
    int i, j, min, st;
    for(i = 1; i <= n ; i++)
    {
        v[i] = 0;   d[i] = map[1][i];
    }
    v[1] = 1;   dist = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && min > d[j])
            {
                st = j;     min = d[j];
            }
        }
        v[st] = 1;  dist += min;
        for(j = 1; j <= n;  j++)
        {
            if(!v[j] && map[st][j] < d[j])  d[j] =  map[st][j];
        }
    }
}

int main(void)
{
    int n, st1, st2, stt, now, i, road;
    while(scanf("%d", &n) && n)
    {
        road = n * (n - 1) / 2;
        for(i = 1; i <= road; i++)
        {
            scanf("%d%d%d%d", &st1, &st2, &stt, &now);
            if(now) map[st2][st1] = map[st1][st2] = 0;
            else map[st1][st2] = map[st2][st1] = stt;
        }
        prim(n);
        printf("%d\n", dist);
    }
    return 0;
}
