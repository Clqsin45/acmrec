#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 14
#define M 2104
#define LL __int64
#define INF 0x3f7f7f7f

int f[M][N], dis[N][N], g[N], n;
void floyd()
{
    int i, j, k;
    for(k = 0; k <= n; k++)
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main(void)
{
    int i, j, k,  x, ans;
    bool flag;
    while(scanf("%d", &n) && n)
    {
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                scanf("%d", &dis[i][j]);
        floyd();

        memset(f, 0x3f, sizeof(f)); ans = f[0][0];

        f[1][0] = 0;    x = (1 << (n + 1)) - 1;
        //printf("%d\n", x);
        for(i = 1; i <= x; i++)
        {
            for(j = 0; j <= n; j++)
            {
                if((i & (1 << j)) == 0 ) continue;
                for(k = 0; k <= n; k++)
                {
                    if(j == k)  continue;
                    f[i | (1 << k)][k] = min(f[i][j] + dis[j][k] , f[i | (1 << k)][k]);
                }
            }
        }
//        for(i = 0; i <= n; i++)
//            ans = min(ans, f[x][i]);
        ans = f[x][0];
        printf("%d\n", ans);
    }
    return 0;
}
