#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define M 110
#define INF 0x3f7f7f7f

int deep[M], s[M * M], q[M * M],v[M * 10], pre[M * 10];
int f[M][M];
int no, m, n;

bool bfs(void)
{
    int h = 0, t = 0, i, j, x;
    memset(deep, -1, sizeof(deep));
    q[0] = 0;   deep[t++] = 0;
    while(h < t)
    {
        x = q[h++];
        for(i = 0; i <= n + 1; i++)
        {
            if(deep[i] == -1 && f[x][i] > 0)
            {
                deep[i] = deep[x] + 1;
                q[t++] = i;
                if(i == n + 1)  return true;
            }
        }
    }
    return false;

}

int dinic(int x, int sum)
{
    int i, flow = sum, now;
    if(x == n + 1)  return sum;
    for(i = 0; i <= n + 1; i++)
    {
        if(deep[i] == deep[x] + 1 && f[x][i] > 0)
        {
            now = dinic(i, min(sum, f[x][i]));
            f[x][i] -= now;
            f[i][x] += now;
            sum -= now;
        }
    }
    return flow - sum;
}
int main(void)
{
    int i, t, k, pr, tol = 0;
    memset(f, 0, sizeof(f));
    memset(pre, 0, sizeof(pre));

    scanf("%d%d", &m, &n);
    for(i = 1; i <= m; i++)
    {
        scanf("%d", &v[i]);
        tol += v[i];
    }

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d", &t);
            if(pre[t] == 0)     f[0][i] += v[t];
            else f[pre[t]][i] = tol;
            pre[t] = i;
        }
        scanf("%d", &t);
        f[i][n + 1] = t;
    }
    int ans = 0;
    while(bfs())
    {
        ans += dinic(0, INF);
    }
    printf("%d\n", ans);
    return 0;
}
