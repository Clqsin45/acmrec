#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MD 210
#define LL long long
#define INF 0x3f7f7f7f
const long long inf=100000000000000LL;
LL f[MD][MD];
int d[MD << 1], q[MD * 100], m[MD << 1][MD << 1];
int n, e;

void init()
{
    int i, j;
    for(i = 0; i <= n + 1; i++)
        for(j = 0; j  <= n + 1; j++)
            f[i][j] = inf;
    return;
}

void floyd()
{
    int i, j, k;

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(f[i][k] != inf && f[k][j] != inf)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

void build(LL mid)
{
    int i, j;
    memset(m, 0, sizeof(m));
    for(i = 1; i <= n; i++)
    {
        m[0][i] = f[0][i];
        m[i][0] = m[e][i + n] = 0;
        m[i + n][e] = f[i][e - n];
        m[i][i + n] = INF;  m[i + n][i] =0;
        for(j = 1; j <= n; j++)
        {
            if(i == j)  continue;
            if(f[i][j] <= mid)
            {
                m[i][j + n] = INF;
                m[j + n][i] = 0;
            }
            else m[i][j + n] = m[j + n][i] = 0;
        }
    }

}

bool bfs()
{
    int f, r, x, y, i;
    f = r = 0;
    memset(d, -1, sizeof(d));
    d[0] = 0;   q[r++] = 0;
    while(f < r)
    {
        x = q[f++];     //printf("%d  %d\n", f, x);
       // system("pause");
        for(i = 0 ; i <= e; i++)
        {
            if(m[x][i] && d[i] == -1)
            {
                d[i] = d[x] + 1;
                if(i == e)
                {
                    return true;
                }
                q[r++] = i;
            }
        }
    }
    return false;
}

int dinic(int x, int sum)
{
    if(x == e)  return sum;
    int flow = 0, nowflow, i;
    for(i = 0; i <= e; i++)
    {
        if(sum && m[x][i] > 0 && d[i] == d[x] + 1)
        {
            nowflow = dinic(i, min(sum, m[x][i]));
            m[x][i] -= nowflow;
            m[i][x] += nowflow;
            sum -= nowflow;
            flow += nowflow;
        }
    }
    return flow;
}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int p, i;
    LL x, y, z, sum = 0, ans = -1, high, low, mid;
    scanf("%d%d", &n, &p);
    init();
    e = n * 2 + 1;

    for(i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x, &y);
        f[0][i] = x;    f[i][e - n] = y;
        sum += x;
    }

    while(p--)
    {
        scanf("%lld%lld%lld", &x, &y, &z);
        f[x][y] = min(z, f[x][y]);
        f[y][x] = min(z, f[y][x]);
    }
    floyd();
    low = 0; high = inf - 1;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        //printf("%lld\n", mid);
        build(mid);
        p = 0;
        while(bfs())
        {
            p += dinic(0, INF);
           // printf("%d\n", p);
        }
        if(p == sum)
        {
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
