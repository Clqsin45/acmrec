#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 40004
#define M 80004
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int now, w, next;
    point(){};
    point(int x, int y, int z): now(x), w(z), next(y) {}
}p[M];
struct askt
{
    int now, no, next;
    askt(){};
    askt(int x, int y, int z): now(x), no(z), next(y) {}
}a[M];

int hp[N], ha[N], f[N], v[N], ans[N], d[N];
int no;

void init(int n)
{
    int i;
    memset(hp, -1, sizeof(hp)); memset(ha, -1, sizeof(ha));
    memset(v, 0, sizeof(v));    no = 0;
    for(i = 1; i <= n; i++) f[i] = i;
}
int find(int x)
{
    if(x == f[x])   return x;
    return f[x] = find(f[x]);
}

void addp(int x, int y, int z)
{
    p[no] = point(y, hp[x], z);   hp[x] = no++;
    p[no] = point(x, hp[y], z);   hp[y] = no++;
}

void adda(int x, int y, int z)
{
    a[no] = askt(y, ha[x], z);    ha[x] = no++;
    a[no] = askt(x, ha[y], z);    ha[y] = no++;
}
void tarjan(int x, int dis)
{
    int i, y, t;
    v[x] = 1;   d[x] = dis;
    for(i = ha[x]; i != -1; i = a[i].next)
    {
        if(!v[y = a[i].now]) continue;
        t = a[i].no;    ans[t] = d[x] + d[y] - 2 * d[find(y)];
    }
    for(i = hp[x]; i != -1; i = p[i].next)
    {
        if(v[y = p[i].now]) continue;
        tarjan(y, dis + p[i].w);    f[y] = x;
    }
}
int main(void)
{
    int TC, i, x, y, z, n, m, t;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d", &n, &m);
        init(n);
        t = n - 1;
        no = 0;
        while(t--)
        {
            scanf("%d%d%d", &x, &y, &z);
            addp(x, y, z);
        }
        no = 0;
        for(t = 1; t <= m; t++)
        {
            scanf("%d%d", &x, &y);
            adda(x, y, t);
        }

        tarjan(1, 0);
        for(i = 1; i <= m; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
