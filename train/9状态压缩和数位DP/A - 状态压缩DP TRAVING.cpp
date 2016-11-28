#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 14
#define M 68888
#define LL __int64
#define INF 0x3f7f7f7f
int f[M][N], val[M][N], dis[N][N], g[N];

void init()
{
    memset(val, 0, sizeof(val));
    int i, j, temp = 1;
    for(i = 1; i < N; i++)
    {
        g[i] = temp;    temp *= 3;
    }
    //for(i = 1; i < N; i++)  printf("%d\n", g[i]);
    for(i = 0; i < M; i++)
    {
        temp = i;
        for(j = 1; temp; j++)
        {
            val[i][j] = temp % 3;
            temp /= 3;
        }
    }
}
int main(void)
{
    init();
    int n, m, ans, i, j , k, x, y, z, flag;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(f, 0x3f, sizeof(f));
        ans = f[0][0];
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            dis[x][y] = dis[y][x] = min(z, dis[x][y]);
        }

        for(i = 1; i <= n; i++) {f[g[i]][i] = 0;   }
        m = g[n + 1] - 1;   //printf("%d\n", m);
        for(i = 1; i <= m; i++)
        {
            flag = 0;
            for(j = 1; j <= n; j++)
            {
                if(val[i][j] == 0)  flag ++;

                for(k = 1; k <= n; k++)
                {
                    if(j == k || dis[j][k] == dis[0][0])  continue;
                    if(val[i][k] == 2)  continue;
                    f[i + g[k]][k] = min(f[i][j] + dis[j][k], f[i + g[k]][k]);
                }
            }
            if(flag == 0)
            {
                for(j = 1; j <= n; j++)
                    ans = min(f[i][j], ans);
             //   printf("%d %d\n", i, ans);
            }

        }
        if(ans == f[0][0])  printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
