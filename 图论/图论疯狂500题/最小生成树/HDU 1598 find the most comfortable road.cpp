#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 204
#define M 1004
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int x, y, z;
    bool operator <(const point& I)const
    {
        return z < I.z;
    }
}p[M];
int f[N], d[N][N], r[N];
int n, m;
void init()
{
    int i;
    for(i = 1;i  <= n; i++) f[i] = i, r[i] = 0;
}

int kruskal(int s)
{
    int i, x, y, ans = 0;
    bool flag = false;
    for(i = s; i <= m; i++)
    {
        x = find(p[i].x);    y = p[i].y;
        if(x == y)  continue;
        ans = max(ans, p[i].z);
        merge(x, y);
    }

}

int main(void)
{
    int i, ans;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(i = 1; i <= m; i++)
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        ans = INF;
        sort(p + 1, p + n + 1);
        for(i = 1; i <= m; i++)
        {
            init();
            ans = min(kruskal(i), ans);
        }
        if(ans == INF)  printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
