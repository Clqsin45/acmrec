#include <stdio.h>
#include <string.h>
#define INF 1000000

int map[102][102], d[102], v[102],q[100002];

void spfa(int s, int n)
{
    int i, x, y, f, r;
    memset(v, 0, sizeof(v));
    for(i = 1; i <=n; i++)  d[i] = INF;
    d[1] = 0;   v[1] = 1;
    for(q[f = r =1] = s; f <= r; f++)
    {
        x = q[f];   v[x] = 0;
        for(y = 1; y <=n ; y++)
        {
            if(x != y && d[y] > (d[x] + map[x][y]))
            {
                d[y] = d[x] + map[x][y];
                if(!v[y])
                {
                    q[++r] = y;     v[y] = 1;
                }
            }
        }

    }
}
int main(void)
{
    int m, n, i, st1, st2, stt;//nµã mÂ·
    while(scanf("%d%d", &n, &m) && (m || n))
    {
        memset(map, 44, sizeof(map));
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&st1, &st2, &stt);
            map[st1][st2] = map[st2][st1] = stt;
        }
        spfa(1, n);
        printf("%d\n", d[n]);
    }
    return 0;
}
