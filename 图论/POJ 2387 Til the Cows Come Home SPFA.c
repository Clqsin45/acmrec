#include <stdio.h>
#include <string.h>
#define INF 10000002

int q[INF], map[1002][1002], d[1002], v[1002];
void spfa(int n)
{
    int i, x, y , f, r, min;
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = INF;
    }
    v[1] = 1;   d[1] = 0;
    for(q[f = r = 1] = 1; f <= r; f++)
    {
        x = q[f];
        v[x] = 0;
        for(y = 1; y <= n; y++)
        {
            if(x != y && d[y] > d[x] + map[x][y])
            {
                d[y] = d[x] + map[x][y];
                if(!v[y])
                {
                    q[++r] = y;
                    v[y] = 1;
                }
            }
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
    spfa(n);
    printf("%d\n", d[n]);

    return 0;
}
