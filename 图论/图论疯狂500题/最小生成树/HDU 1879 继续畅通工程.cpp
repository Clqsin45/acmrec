#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 103
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N][N], d[N], ans, n;
bool v[N];

void prim()
{
    int i, j, now, temp;
    ans = 0;
    for(i = 1; i <= n; i++)
    {
        d[i] = f[1][i]; v[i] = false;
    }
    d[1] = 0;    v[1] = true;
    for(i = 1; i < n; i++)
    {
        now = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && now > d[j])
            {
                now = d[j]; temp = j;
            }
        }
        ans += now; v[temp] = true;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > f[temp][j])
                d[j] = f[temp][j];
        }
    }
}

int main(void)
{
    int m, i, j;
    int x, y, z, k;
    while(scanf("%d", &n) && n)
    {
        m = n * (n - 1) / 2;
        while(m--)
        {
            scanf("%d%d%d%d", &x, &y, &z, &k);
            if(k)   f[x][y] = f[y][x] = 0;
            else f[x][y] = f[y][x] = z;
        }
        prim();
        printf("%d\n", ans);
    }
    return 0;
}
