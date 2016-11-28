#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 104
#define M 10004
#define LL __int64
#define INF 0x3f7f7f7f
int head[N], dfn[N], low[N], v[N];
bool ge[N];
int n, root, top, num, no, loc;
struct point
{
    int now, next;
    point() {};
    point(int x, int y):now(x), next(y){};
}p[M];
void init()
{
    memset(head, -1, sizeof(head)); memset(dfn, -1, sizeof(dfn));
    memset(ge, false, sizeof(ge));  no = num = top = loc = 0;
}

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
    p[no] = point(x, head[y]);  head[y] = no++;
}

void tarjan(int x, int fa)
{
    int i, y, ct = 0;
    dfn[x] = low[x] = ++loc;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(dfn[y] == -1)
        {
            ct++;   tarjan(y, x);
            low[x] = min(low[x], low[y]);
            if((x == root && ct > 1) || (x != root && dfn[x] <= low[y]))
                ge[x] = true;
        }
        else if(y != fa)    low[x] = min(low[x], dfn[y]);
    }
}
int main(void)
{
    int i, x, y, ans;
    while(scanf("%d", &n) && n)
    {
        init();
        while(scanf("%d", &x) && x)
        {
            while(getchar() != '\n')
            {
                scanf("%d", &y);
                add(x, y);
            }
        }

        for(i = 1; i <= n; i++)
        {
            if(dfn[i] == -1)    {root = i, tarjan(i, -1);}
        }

        for(i = 1, ans = 0; i <= n; i++)
            ans += ge[i];
        printf("%d\n", ans);
    }
    return 0;
}
