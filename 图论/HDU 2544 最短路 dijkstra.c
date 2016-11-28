#include <stdio.h>
#include <string.h>
#define INF 1000000
int f[102][102], v[102], d[102];
void dijkstra(int n)
{
    int i, j, st, min;
    memset(v, 0, sizeof(v));
    for(i = 1; i <= n; i++) d[i] = f[1][i];
    d[1] = 0;  v[1] = 1;
    for(i = 1; i <= n; i++)
    {
        min = INF;  st = 1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && min > d[j])
            {
                st = j;
                min = d[j];
            }
        }
        v[st] = 1;
        for(j = 1; j <=n ; j++)
        {
            if(!v[j] && d[j] > d[st] + f[st][j])
            {
                    d[j] = d[st] + f[st][j];
            }
        }

    }
}
int main(void)
{
    int m, n, i, j, st1, st2, stt;
    while(scanf("%d%d", &n , &m) && (m || n))
    {
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n ; j++)    f[i][j] = INF;
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            //if(stt < f[i][j])
             f[st1][st2] = f[st2][st1] = stt;
        }
        dijkstra(n);
        printf("%d\n",d[n]);
    }
    return 0;
}
